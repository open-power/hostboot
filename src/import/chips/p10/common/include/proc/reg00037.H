/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00037.H $         */
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

#ifndef __PROC_REG00037_H_
#define __PROC_REG00037_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q2_OCB_OCI_OPIT4Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT7Q6_OCB_OCI_OPIT7Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C15_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C17RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C22_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C25RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C8RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C10RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C13_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C2_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C22RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_OCI, TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C8RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_OCI1,
                           TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITDPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI, TP_TPCHIP_OCC_OCI_OCB_OTBR_RW));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OTBR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTBR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OTBR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTBR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTBR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OTBR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI, TP_TPCHIP_OCC_OCI_OCB_OTBR_RW));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTBR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI, TP_TPCHIP_OCC_OCI_OCB_OTBR_RW));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE,
           TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI, TP_TPCHIP_OCC_OCI_OCB_OTBR_RW));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE,
           TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTBR_OCI, TP_TPCHIP_OCC_OCI_OCB_OTBR_RW));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE,
           TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTBR_OCB_OCI_OTBR_TIMEBASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_ACK_DETECTED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_PING_DETECT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_TX_ECC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_INTERCHIP_RX_ECC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_SEND_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RECV_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_MST_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_OCI, TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICSTAT_PING_SLV_STATE_MACHINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_I_REGION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2_B_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG104_REGISTER104 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG33_REGISTER33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG52_REGISTER52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG65_REGISTER65 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG90_REGISTER90 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_DBG_DEBUG_TRACE_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_SPATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_LXSTOP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_ANY_HOSTATTN_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_SKITTER_DATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CFIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_RECOV(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_RECOV;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_RECOV(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_RECOV;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_RECOV, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_RECOV(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_RECOV, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_ANY_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_ANY_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_ANY_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_ANY_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_ANY_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_ANY_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_ANY_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RESERVED1R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RESERVED1R(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RESERVED1R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RESERVED1R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RESERVED1R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RESERVED1R,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RESERVED1R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RESERVED3R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RESERVED3R(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RESERVED3R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RESERVED3R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RESERVED3R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RESERVED3R,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RESERVED3R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_RECOV_RECOV_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_RECOV_RECOV_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_RECOV_RECOV_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_RECOV_RECOV_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_RECOV_RECOV_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_RECOV_RECOV_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_RECOV_RECOV_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_RECOV_RECOV_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_RECOV));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_RECOV_RECOV_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_RECOV_RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_SCAN64CONTSCAN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_SCAN64CONTSCAN;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_SCAN64CONTSCAN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_SCAN64CONTSCAN));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_SCAN64CONTSCAN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_I2C_IMM_SET_S_SCL_A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI, TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMPLEMENT_MASK_COMPLEMENT_MASK_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CRSIC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_RSIC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP0_WO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP3_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP2_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MECTRL_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
