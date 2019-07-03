/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00011.H $          */
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

#ifndef __MCC_REG00011_H_
#define __MCC_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTOKEY1B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY1B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTOKEY1B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY1B;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY1B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTOKEY1B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1B));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY1B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1B));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B,
           CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1B));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B,
           CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1B));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B,
           CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLCREDIT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLCREDIT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLCREDIT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLCREDIT;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLCREDIT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLCREDIT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLCREDIT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XVC0_CREDIT_INIT,
           DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XVC0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XVC0_CREDIT_INIT,
           DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XVC0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_XVC0_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_XVC0_CREDIT_INIT,
           DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XVC0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XVC3_CREDIT_INIT,
           DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XVC3_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XVC3_CREDIT_INIT,
           DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XVC3_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_XVC3_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_XVC3_CREDIT_INIT,
           DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XVC3_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT,
           DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT,
           DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT,
           DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_VC0_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_VC0_CREDIT_INIT,
           DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_VC0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_VC0_CREDIT_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_VC0_CREDIT_INIT,
           DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_VC0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_VC0_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_VC0_CREDIT_INIT,
           DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_VC0_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_VC1_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_VC1_CREDIT_INIT,
           DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_VC1_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_VC1_CREDIT_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_VC1_CREDIT_INIT,
           DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_VC1_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_VC1_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_VC1_CREDIT_INIT,
           DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_VC1_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_DCP1_CREDIT_INIT,
           DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_DCP1_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_DCP1_CREDIT_INIT,
           DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_DCP1_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_DCP1_CREDIT_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_DCP1_CREDIT_INIT,
           DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_DCP1_CREDIT_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XDCP0_CHANA_POOL,
           DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CHANA_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XDCP0_CHANA_POOL,
           DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CHANA_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_XDCP0_CHANA_POOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_XDCP0_CHANA_POOL,
           DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CHANA_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XDCP0_CHANB_POOL,
           DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CHANB_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return o_data.insertFromRight<DSTL_DSTLCREDIT_XDCP0_CHANB_POOL,
           DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CHANB_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCREDIT_XDCP0_CHANB_POOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCREDIT));
#endif
    return i_data.extractToRight<DSTL_DSTLCREDIT_XDCP0_CHANB_POOL,
           DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCREDIT_XDCP0_CHANB_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIR_RW;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIR_WO_AND;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIR_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIR_WO_OR;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_DECRYPT_ERR_INFO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_DECRYPT_ERR_INFO,
           DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_DECRYPT_ERR_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_DECRYPT_ERR_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_DECRYPT_ERR_INFO,
           DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_DECRYPT_ERR_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_DECRYPT_ERR_INFO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_DECRYPT_ERR_INFO,
           DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_DECRYPT_ERR_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_ENCRYPT_ERR_INFO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_ENCRYPT_ERR_INFO,
           DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_ENCRYPT_ERR_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_ENCRYPT_ERR_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_ENCRYPT_ERR_INFO,
           DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_ENCRYPT_ERR_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_ENCRYPT_ERR_INFO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_ENCRYPT_ERR_INFO,
           DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_ENCRYPT_ERR_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SPARE37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SPARE37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SPARE37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SPARE37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SPARE37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SPARE37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SPARE37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SPARE37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SPARE37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SPARE37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SPARE37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SPARE37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SPARE38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SPARE38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SPARE38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIR_SPARE38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIR_SPARE38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.setBit<DSTL_DSTLFIR_SPARE38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLFIR_SPARE38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return o_data.clearBit<DSTL_DSTLFIR_SPARE38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIR_SPARE38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIR_SPARE38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLFIR_SPARE38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIR_RW, DSTL_DSTLFIR_WO_AND, DSTL_DSTLFIR_WO_OR));
#endif
    return i_data.getBit<DSTL_DSTLFIR_SPARE38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIR_SPARE38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLERRRPT;
#endif
    return fapi2::getScom(i_target, USTL_USTLERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLERRRPT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return fapi2::putScom(i_target, USTL_USTLERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_RDCMD_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BADCRC_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_FLIT_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BAD_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_SUE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_DATA_BUFFER_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_READ_RESPONSE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_COMP_META_NOT_VALID_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_MCHWFM_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_REG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_DBG_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CNFG_INJ_FIR_PE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_TMPL9_TO_MANY_DATA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_TMPL9_TO_MANY_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_EXCESS_DATA_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANA_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_CHANB_META_PARITY_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANA_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.setBit<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return o_data.clearBit<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRRPT));
#endif
    return i_data.getBit<USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRRPT_READ_USTL_DUPLICATE_OW_CHANB_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIRWOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRWOF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRWOF;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIRWOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIRWOF(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRWOF));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIRWOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRWOF_USTLFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRWOF));
#endif
    return o_data.insertFromRight<USTL_USTLFIRWOF_USTLFIRWOF_WOF,
           USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRWOF_USTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRWOF_USTLFIRWOF_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRWOF));
#endif
    return o_data.insertFromRight<USTL_USTLFIRWOF_USTLFIRWOF_WOF,
           USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRWOF_USTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIRWOF_USTLFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRWOF));
#endif
    return i_data.extractToRight<USTL_USTLFIRWOF_USTLFIRWOF_WOF,
           USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRWOF_USTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
