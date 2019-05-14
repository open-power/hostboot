/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00038.H $         */
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

#ifndef __PROC_REG00038_H_
#define __PROC_REG00038_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP1_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SCI1M(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCI1M;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SCI1M(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCI1M;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCI1M, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SCI1M(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SCI1M));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCI1M, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCRSIC4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SI1M(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI1M;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SI1M(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI1M;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI1M, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SI1M(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SI1M));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI1M, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SI2S(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI2S;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SI2S(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI2S;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI2S, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SI2S(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SI2S));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI2S, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SMODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SMODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SMODE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SMODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SMODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SMODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_WARM_START_COMPLETED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_OWN_ID_THIS_FSI_SLAVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_ECHO_DELAY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_SEND_DELAY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_LBUS_CLOCK_DIVIDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SRSIM4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIM4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SRSIM4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIM4;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIM4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SRSIM4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SRSIM4));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIM4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SSMBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSMBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SSMBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSMBL;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSMBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SSMBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SSMBL));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSMBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP4_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MREFP0_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SOML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SOML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SOML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SOML;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SOML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SOML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SOML));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SOML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_PEEK4B0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4B0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_PEEK4B0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4B0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4B0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_PEEK4B0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4B0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4B0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_CQERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_CQERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_CQERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_CQERRRPT;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_CQERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_CQERRRPT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_CQERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_PGMIG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_PGMIG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG2;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_PGMIG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_PGMIG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PGMIG2));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_PGMIG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_DBGNORTH(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_DBGNORTH;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_DBGNORTH(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_DBGNORTH;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_DBGNORTH, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_DBGNORTH(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_DBGNORTH, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WCMBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WCMBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WCMBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WCMBAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WCMBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WCMBAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WCMBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR,
           VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR,
           VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR,
           VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
