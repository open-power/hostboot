/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00010.H $         */
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

#ifndef __NMMU_REG00010_H_
#define __NMMU_REG00010_H_

namespace scomt
{
namespace nmmu
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_RWX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_RWX;
#endif
    return fapi2::getScom(i_target, FIR1_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_REG_RWX(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, FIR1_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WOX_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WOX_AND;
#endif
    return fapi2::getScom(i_target, FIR1_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, FIR1_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WOX_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_REG_WOX_OR;
#endif
    return fapi2::getScom(i_target, FIR1_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, FIR1_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_DIR_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_DIR_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_LRU_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_LRU_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_MULTIHIT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SLB_MULTIHIT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_DIR_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_DIR_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_LRU_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_LRU_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_MULTIHIT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TLB_MULTIHIT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SEG_FAULT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SEG_FAULT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SEG_FAULT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_SEG_FAULT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_SEID_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PTE_UPD_FAIL_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_GUEST_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_HOST_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INVALID_WIMG_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INVALID_WIMG_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INVALID_WIMG_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_INVALID_WIMG_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INV_RDX_QUAD_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_FOREIGN_ADDR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PREFETCH_ABT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_CXT_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_PWC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NX0_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP0_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP1_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NPU_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.insertFromRight<FIR1_REG_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.setBit<FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return o_data.clearBit<FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.extractToRight<FIR1_REG_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_REG_RWX, FIR1_REG_WOX_AND, FIR1_REG_WOX_OR));
#endif
    return i_data.getBit<FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_ERR_LOG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_ERR_LOG;
#endif
    return fapi2::getScom(i_target, NMMU_ERR_LOG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return fapi2::putScom(i_target, NMMU_ERR_LOG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.setBit<NMMU_ERR_LOG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.clearBit<NMMU_ERR_LOG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.getBit<NMMU_ERR_LOG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.setBit<NMMU_ERR_LOG_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.clearBit<NMMU_ERR_LOG_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.getBit<NMMU_ERR_LOG_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.setBit<NMMU_ERR_LOG_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.clearBit<NMMU_ERR_LOG_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.getBit<NMMU_ERR_LOG_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MULT_SEL,
           NMMU_ERR_LOG_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_LOG_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return o_data.insertFromRight<NMMU_ERR_LOG_MULT_SEL,
           NMMU_ERR_LOG_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_LOG_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_LOG));
#endif
    return i_data.extractToRight<NMMU_ERR_LOG_MULT_SEL,
           NMMU_ERR_LOG_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_LOG_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
