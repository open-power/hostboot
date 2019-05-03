/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00005.H $          */
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

#ifndef __MCC_REG00005_H_
#define __MCC_REG00005_H_

namespace scomt
{
namespace mcc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTONONCEA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTONONCEA;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEA));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEA));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEA));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEA));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTONONCEB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTONONCEB;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEB));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEB));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEB));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEB));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLOCAPIERROR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLOCAPIERROR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLOCAPIERROR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLOCAPIERROR;
#endif
    return fapi2::getScom(i_target, USTL_USTLOCAPIERROR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLOCAPIERROR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return fapi2::putScom(i_target, USTL_USTLOCAPIERROR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.insertFromRight<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.insertFromRight<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.setBit<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.clearBit<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return i_data.extractToRight<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return i_data.getBit<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.insertFromRight<USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE,
           USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.insertFromRight<USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE,
           USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return i_data.extractToRight<USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE,
           USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.insertFromRight<USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION,
           USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.insertFromRight<USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION,
           USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return i_data.extractToRight<USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION,
           USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_WRTDBGMCA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRTDBGMCA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_WRTDBGMCA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRTDBGMCA;
#endif
    return fapi2::getScom(i_target, WRITE_WRTDBGMCA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_WRTDBGMCA(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return fapi2::putScom(i_target, WRITE_WRTDBGMCA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_MCA_DBG_SEL_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_MCA_DBG_SEL_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_MCA_DBG_SEL_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_MCA_DBG_SEL_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_MCA_DBG_SEL_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_MCA_DBG_SEL_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_MCA_DBG_SEL_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_MCA_DBG_SEL_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_MCA_DBG_SEL_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_MCA_DBG_SEL_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_MCA_DBG_SEL_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_MCA_DBG_SEL_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_DBG_SPARE_MCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_DBG_SPARE_MCA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_DBG_SPARE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_DBG_SPARE_MCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_DBG_SPARE_MCA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_DBG_SPARE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_DBG_SPARE_MCA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_DBG_SPARE_MCA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_DBG_SPARE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_DBG_SPARE_MCA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_DBG_SPARE_MCA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_DBG_SPARE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_DBG_SPARE_MCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_DBG_SPARE_MCA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_DBG_SPARE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_DBG_SPARE_MCA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_DBG_SPARE_MCA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_DBG_SPARE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.setBit<WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.clearBit<WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.getBit<WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT_SPARE1_MCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT_SPARE1_MCA,
           WRITE_WRTDBGMCA_WAT_SPARE1_MCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_SPARE1_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT_SPARE1_MCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT_SPARE1_MCA,
           WRITE_WRTDBGMCA_WAT_SPARE1_MCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_SPARE1_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WAT_SPARE1_MCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WAT_SPARE1_MCA,
           WRITE_WRTDBGMCA_WAT_SPARE1_MCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT_SPARE1_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA,
           WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA,
           WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA,
           WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA,
           WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return o_data.insertFromRight<WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA,
           WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTDBGMCA));
#endif
    return i_data.extractToRight<WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA,
           WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
