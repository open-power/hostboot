/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00013.H $         */
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

#ifndef __PROC_REG00013_H_
#define __PROC_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1RR_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q1RR_OCB_OCI_OPIT5Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q1RR_OCB_OCI_OPIT6Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q1RR_OCB_OCI_OPIT7Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q5_OCB_OCI_OPIT7Q5RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C16;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C16;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C16, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C16, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C19RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C21;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C21;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C21, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C21));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C21, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C21));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C21));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C21_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C6RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C1_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C10;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C10;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C27;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C27;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C27, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C27));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C27, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C27));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C27));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C27));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C27));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C27));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C27));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C27_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C6RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2RR_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0RR_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OUISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OUISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OUISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OUISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OUISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OUISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OUISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OUISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OUISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OUISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OUISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OUISR1_INTERRUPT_UNCON_STATUS_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_SRAM_CTL_SREAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SREAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_SRAM_CTL_SREAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SREAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SREAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_SRAM_CTL_SREAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SREAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SREAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SREAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS,
           TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SREAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS,
           TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SREAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS,
           TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SREAR_SRAM_SREAR_ERROR_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG107_REGISTER107 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG118_REGISTER118 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG18_REGISTER18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG30_REGISTER30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG51_REGISTER51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG66_REGISTER66 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG79_REGISTER79 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG93_REGISTER93 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_FIFO_SIZE_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_MSM_CURR_STATE_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SCL_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SDA_SYN_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_S_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SCL_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_M_SDA_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_HIGH_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LOW_WATER_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_I2C_BUSY_EXT_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_SELF_BUSY_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_PEEK_DATA1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_EXTENDED_STATUS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002,
           TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002,
           TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002,
           TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_FIFO_BITS_READ0_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002,
           TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002,
           TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002,
           TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_PEEK_DATA1_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_FIFO1_REGISTER_READ_D_LBUS_PARITY_ERR1_002 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_ERR_C_IMM_RESET_ERRORS_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_I2C_E_IMM_RESET_I2C_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_RESET_S_SDA_C_IMM_RESET_S_SDA_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_IMM_SET_S_SCL_B_IMM_SET_S_SCL_000 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_INTERRUPTS_E;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_INTERRUPTS_E;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_INTERRUPTS_E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_INTERRUPTS_E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_INTS_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_PEEK_DATA1_003 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPTS_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPTS_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_INT_MASK_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003,
           TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_PEEK_DATA1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_INTERRUPT_MASK_REGISTER_READ_E_LBUS_PARITY_ERR1_003 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_LOCK_ENABLE_001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001,
           TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001,
           TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001,
           TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ID_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001,
           TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001,
           TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001,
           TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_PIBI2CM_ATOMIC_LOCK_REG_C_ACTIVITY_001 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_I2CM_RESET_REGISTER_D_OVERALL_RESET_002 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA,
           TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA,
           TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA,
           TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_OTP_OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST4_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING,
           TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING,
           TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING,
           TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT,
           TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT,
           TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT,
           TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_CORRECTED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_UNCORRECTED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS,
           TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS,
           TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS,
           TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_ARRAY_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION,
           TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION,
           TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION,
           TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_ECC_CAPTURE_REG_BIT_LOCATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
