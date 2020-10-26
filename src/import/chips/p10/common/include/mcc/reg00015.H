/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00015.H $          */
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

#ifndef __MCC_REG00015_H_
#define __MCC_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[CRYPTO_DECRYPT_CRYPTONONCEB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTONONCEB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CRYPTO_DECRYPT_CRYPTONONCEB]

//>> GET_[CRYPTO_DECRYPT_CRYPTONONCEB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTONONCEB;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTONONCEB]

//>> PUT_[CRYPTO_DECRYPT_CRYPTONONCEB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTONONCEB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTONONCEB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CRYPTO_DECRYPT_CRYPTONONCEB]


//>> SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]

//>> SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]

//>> GET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTONONCEB));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB,
           CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB]

//>> PREP_[CRYPTO_ENCRYPT_CRYPTONONCEA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTONONCEA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CRYPTO_ENCRYPT_CRYPTONONCEA]

//>> GET_[CRYPTO_ENCRYPT_CRYPTONONCEA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTONONCEA;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTONONCEA]

//>> PUT_[CRYPTO_ENCRYPT_CRYPTONONCEA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTONONCEA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTONONCEA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CRYPTO_ENCRYPT_CRYPTONONCEA]


//>> SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]

//>> SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]

//>> GET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTONONCEA));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA,
           CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
