/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00077.H $         */
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

#ifndef __PROC_REG00077_H_
#define __PROC_REG00077_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_WOX));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP1_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SNML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SNML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SNML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SNML;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SNML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SNML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SNML));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SNML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SSISM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSISM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SSISM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSISM;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSISM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SSISM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSISM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSISM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SSTAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSTAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSTAT;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSTAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SSTAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSTAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_WCBSBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_WCBSBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_WCBSBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_WCBSBAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_WCBSBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_WCBSBAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_WCBSBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR,
           VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR,
           VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR,
           VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_RWX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_RWX;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WOX_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WOX_AND;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WOX_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WOX_OR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_LINK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_LINK_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RWX, VAS_VA_RG_SCF_FIR_REG_WOX_AND, VAS_VA_RG_SCF_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
