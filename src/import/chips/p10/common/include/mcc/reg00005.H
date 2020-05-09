/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00005.H $          */
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

#ifndef __MCC_REG00005_H_
#define __MCC_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[CRYPTO_DECRYPT_CRYPTONONCEA]
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
//<< PREP_[CRYPTO_DECRYPT_CRYPTONONCEA]

//>> GET_[CRYPTO_DECRYPT_CRYPTONONCEA]
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
//<< GET_[CRYPTO_DECRYPT_CRYPTONONCEA]

//>> PUT_[CRYPTO_DECRYPT_CRYPTONONCEA]
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
//<< PUT_[CRYPTO_DECRYPT_CRYPTONONCEA]


//>> SET_[CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA]

//>> SET_[CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA]

//>> GET_[CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA]

//>> PREP_[CRYPTO_ENCRYPT_CRYPTONONCEB]
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
//<< PREP_[CRYPTO_ENCRYPT_CRYPTONONCEB]

//>> GET_[CRYPTO_ENCRYPT_CRYPTONONCEB]
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
//<< GET_[CRYPTO_ENCRYPT_CRYPTONONCEB]

//>> PUT_[CRYPTO_ENCRYPT_CRYPTONONCEB]
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
//<< PUT_[CRYPTO_ENCRYPT_CRYPTONONCEB]


//>> SET_[CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB]

//>> SET_[CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB]

//>> GET_[CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB]

//>> PREP_[DSTL_DSTLTRACK2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLTRACK2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLTRACK2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DSTL_DSTLTRACK2]

//>> GET_[DSTL_DSTLTRACK2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLTRACK2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLTRACK2;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLTRACK2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DSTL_DSTLTRACK2]

//>> PUT_[DSTL_DSTLTRACK2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLTRACK2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK2));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLTRACK2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DSTL_DSTLTRACK2]


//>> SET_[DSTL_DSTLTRACK2_POOL_CURRENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK2_POOL_CURRENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK2));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK2_POOL_CURRENT_COUNT,
           DSTL_DSTLTRACK2_POOL_CURRENT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLTRACK2_POOL_CURRENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLTRACK2_POOL_CURRENT_COUNT]

//>> SET_[DSTL_DSTLTRACK2_POOL_CURRENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK2_POOL_CURRENT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK2));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK2_POOL_CURRENT_COUNT,
           DSTL_DSTLTRACK2_POOL_CURRENT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLTRACK2_POOL_CURRENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLTRACK2_POOL_CURRENT_COUNT]

//>> GET_[DSTL_DSTLTRACK2_POOL_CURRENT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK2_POOL_CURRENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK2));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK2_POOL_CURRENT_COUNT,
           DSTL_DSTLTRACK2_POOL_CURRENT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLTRACK2_POOL_CURRENT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLTRACK2_POOL_CURRENT_COUNT]

//>> SET_[DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK2));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT,
           DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT]

//>> SET_[DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK2));
#endif
    return o_data.insertFromRight<DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT,
           DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT]

//>> GET_[DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLTRACK2));
#endif
    return i_data.extractToRight<DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT,
           DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLTRACK2_READ_WDF_CURRENT_COUNT]

//>> PREP_[USTL_USTLOCAPIERROR]
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
//<< PREP_[USTL_USTLOCAPIERROR]

//>> GET_[USTL_USTLOCAPIERROR]
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
//<< GET_[USTL_USTLOCAPIERROR]

//>> PUT_[USTL_USTLOCAPIERROR]
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
//<< PUT_[USTL_USTLOCAPIERROR]


//>> SET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]

//>> SET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]

//>> SET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.setBit<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]

//>> CLEAR_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return o_data.clearBit<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]

//>> GET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]

//>> GET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]
static inline bool GET_USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLOCAPIERROR));
#endif
    return i_data.getBit<USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID]

//>> SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE]

//>> SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE]

//>> GET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE]

//>> SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION]

//>> SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION]

//>> GET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
