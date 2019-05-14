/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00002.H $          */
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

#ifndef __MCC_REG00002_H_
#define __MCC_REG00002_H_

namespace scomt
{
namespace mcc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTOKEY2A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY2A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTOKEY2A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY2A;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY2A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTOKEY2A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2A));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY2A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2A));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A,
           CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2A));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A,
           CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2A));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A,
           CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSLTWAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSLTWAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSLTWAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSLTWAT;
#endif
    return fapi2::getScom(i_target, DSTL_DSLTWAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSLTWAT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return fapi2::putScom(i_target, DSTL_DSLTWAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_ACT_PMU,
           DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_ACT_PMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_ACT_PMU,
           DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_ACT_PMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANA_WAT_ACT_PMU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANA_WAT_ACT_PMU,
           DSTL_DSLTWAT_CHANA_WAT_ACT_PMU_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_ACT_PMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_ACT_PMU,
           DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_ACT_PMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_ACT_PMU,
           DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_ACT_PMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANB_WAT_ACT_PMU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANB_WAT_ACT_PMU,
           DSTL_DSLTWAT_CHANB_WAT_ACT_PMU_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_ACT_PMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN,
           DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN,
           DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN,
           DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_DLY_CREDIT_RETURN_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN,
           DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN,
           DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN,
           DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_DLY_CREDIT_RETURN_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN,
           DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN,
           DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN,
           DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_NULL_FLIT_STALL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN,
           DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN,
           DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN,
           DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_NULL_FLIT_STALL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXVC3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXVC3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN,
           DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANA_WAT_HOLD_TLXDCP0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN,
           DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_CHANB_WAT_HOLD_TLXDCP0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_RESERVED_24_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_RESERVED_24_62,
           DSTL_DSLTWAT_RESERVED_24_62_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_RESERVED_24_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSLTWAT_RESERVED_24_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return o_data.insertFromRight<DSTL_DSLTWAT_RESERVED_24_62,
           DSTL_DSLTWAT_RESERVED_24_62_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_RESERVED_24_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSLTWAT_RESERVED_24_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSLTWAT));
#endif
    return i_data.extractToRight<DSTL_DSLTWAT_RESERVED_24_62,
           DSTL_DSLTWAT_RESERVED_24_62_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSLTWAT_RESERVED_24_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIR_RW;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIR_WO_AND;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIR_WO_OR;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_UNEXP_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_UNEXP_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_UNEXP_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_UNEXP_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_UNEXP_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RESERVED_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RESERVED_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_RESERVED_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_RESERVED_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_RESERVED_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_RESERVED_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_RESERVED_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_RESERVED_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_RESERVED_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_BUFFER_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_BUFFER_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_TAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_TAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_TAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_TAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_TAG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_TAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_TAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_TAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_SCOM_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RESERVED_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RESERVED_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_RESERVED_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_RESERVED_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_RESERVED_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_RESERVED_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_RESERVED_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RESERVED_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_CMT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WDF_CMT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WDF_CMT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WDF_CMT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WDF_CMT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WDF_CMT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WDF_CMT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WDF_CMT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_READ_SPARE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_SPARE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_READ_SPARE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_READ_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_READ_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_READ_SPARE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_READ_SPARE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_READ_SPARE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_READ_SPARE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_SPARE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_READ_SPARE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_READ_SPARE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_READ_SPARE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_READ_SPARE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_READ_SPARE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_READ_SPARE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_SPARE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WRT_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WRT_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WRT_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WRT_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WRT_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WRT_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WRT_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WRT_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WRT_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WRT_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFFER_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WRT_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WRT_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WRT_BUFFER_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WRT_BUFFER_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WRT_BUFFER_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFFER_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_SCOM_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WRT_SCOM_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WRT_SCOM_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_SCOM_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_DATA_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WRT_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WRT_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WRT_DATA_SYNDROME_NE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WRT_DATA_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WRT_DATA_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_WRT_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_WRT_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_WRT_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_WRT_BUFF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_WRT_BUFF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_WRT_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_WRT_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_LOL_DROP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_LOL_DROP_RECOVER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_LOL_DROP_RECOVER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_LOL_DROP_RECOVER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_LOL_DROP_RECOVER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BAD_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_BAD_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_BAD_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BAD_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_BAD_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_BAD_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_INVALID_CMD_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_INVALID_CMD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_INVALID_CMD_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_INVALID_CMD_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_CMD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_FATAL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_FATAL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_FATAL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_FATAL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_FATAL_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_FATAL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_FATAL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_FATAL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RECOV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_RECOV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_RECOV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_RECOV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_RECOV_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_RECOV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_RECOV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_RECOV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_SPARE_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_SPARE_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIR_SPARE_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.setBit<USTL_USTLFIR_SPARE_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return o_data.clearBit<USTL_USTLFIR_SPARE_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIR_SPARE_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLFIR_SPARE_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIR_RW, USTL_USTLFIR_WO_AND, USTL_USTLFIR_WO_OR));
#endif
    return i_data.getBit<USTL_USTLFIR_SPARE_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIR_SPARE_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WDF_WBMGR_TAG_INFO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WDF_WBMGR_TAG_INFO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WDF_WBMGR_TAG_INFO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WDF_WBMGR_TAG_INFO;
#endif
    return fapi2::getScom(i_target, WDF_WBMGR_TAG_INFO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WDF_WBMGR_TAG_INFO(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return fapi2::putScom(i_target, WDF_WBMGR_TAG_INFO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.setBit<WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.clearBit<WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.extractToRight<WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.getBit<WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE0_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.setBit<WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.clearBit<WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.extractToRight<WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.getBit<WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE1_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.setBit<WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.clearBit<WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.extractToRight<WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.getBit<WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE2_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.setBit<WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.clearBit<WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.extractToRight<WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.getBit<WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_SLICE3_BUFFER_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_TAG_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_TAG_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_TAG_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_TAG_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.insertFromRight<WDF_WBMGR_TAG_INFO_TAG_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_TAG_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WBMGR_TAG_INFO_TAG_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.setBit<WDF_WBMGR_TAG_INFO_TAG_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_TAG_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WBMGR_TAG_INFO_TAG_OVERRUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return o_data.clearBit<WDF_WBMGR_TAG_INFO_TAG_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_TAG_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WBMGR_TAG_INFO_TAG_OVERRUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.extractToRight<WDF_WBMGR_TAG_INFO_TAG_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_TAG_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WBMGR_TAG_INFO_TAG_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WBMGR_TAG_INFO));
#endif
    return i_data.getBit<WDF_WBMGR_TAG_INFO_TAG_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WBMGR_TAG_INFO_TAG_OVERRUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
