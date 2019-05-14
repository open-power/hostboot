/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00042.H $         */
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

#ifndef __PROC_REG00042_H_
#define __PROC_REG00042_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP0_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SCMBR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SCMBR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SCMBR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SCMBR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SCMBR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SCMBR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SCMBR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SCMBR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SMBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SMBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SMBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SMBL;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SMBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SMBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SMBL));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SMBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SSI2M(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSI2M;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SSI2M(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSI2M;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSI2M, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SSI2M(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSI2M));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSI2M, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_PEEK4A8(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4A8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4A8;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4A8, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_PEEK4A8(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4A8, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A8));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A8_PORT_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_PORT_CONTROL_PORT_CONTROL_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_N2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_LOOPCOUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_INTERNALCOUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_SHIFTER_FSM_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N1_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_N2_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_COUNTER_COUNT_RESERVED_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON0BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON0BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON0BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON0BAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON0BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON0BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON0BAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON0BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON4CMP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON4CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON4CMP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON4CMP;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON4CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON4CMP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON4CMP));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON4CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON5WID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON5WID;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON5WID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON5WID;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON5WID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON5WID(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON5WID));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON5WID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
