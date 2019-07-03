/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00012.H $          */
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

#ifndef __MCC_REG00012_H_
#define __MCC_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT0;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRACT0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT0));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT0));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0,
           DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT0));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0,
           DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT0));
#endif
    return i_data.extractToRight<DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0,
           DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLPSAVE1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLPSAVE1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLPSAVE1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLPSAVE1;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLPSAVE1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLPSAVE1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLPSAVE1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_A_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE,
           DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_MASTER_PSAVE_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_RESERVED_59_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_RESERVED_59_63,
           DSTL_DSTLPSAVE1_RESERVED_59_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_RESERVED_59_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE1_RESERVED_59_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE1_RESERVED_59_63,
           DSTL_DSTLPSAVE1_RESERVED_59_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_RESERVED_59_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE1_RESERVED_59_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE1));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE1_RESERVED_59_63,
           DSTL_DSTLPSAVE1_RESERVED_59_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE1_RESERVED_59_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLTRACK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLTRACK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLTRACK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLTRACK;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLTRACK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLTRACK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLTRACK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXDCP0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXDCP0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC0_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE,
           DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANA_BUFFER_TLXVC3_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE,
           DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_CHANB_BUFFER_TLXVC3_AVAILABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXVC0_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXVC3_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW,
           DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLTRACK_TLXDCP0_CREDIT_TOTAL_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLDBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLDBG;
#endif
    return fapi2::getScom(i_target, USTL_USTLDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLDBG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return fapi2::putScom(i_target, USTL_USTLDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_0,
           USTL_USTLDBG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_0,
           USTL_USTLDBG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLDBG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return i_data.extractToRight<USTL_USTLDBG_0,
           USTL_USTLDBG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_1,
           USTL_USTLDBG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_1,
           USTL_USTLDBG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLDBG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return i_data.extractToRight<USTL_USTLDBG_1,
           USTL_USTLDBG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_2,
           USTL_USTLDBG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_2,
           USTL_USTLDBG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLDBG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return i_data.extractToRight<USTL_USTLDBG_2,
           USTL_USTLDBG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_3,
           USTL_USTLDBG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLDBG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return o_data.insertFromRight<USTL_USTLDBG_3,
           USTL_USTLDBG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLDBG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLDBG));
#endif
    return i_data.extractToRight<USTL_USTLDBG_3,
           USTL_USTLDBG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLDBG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
