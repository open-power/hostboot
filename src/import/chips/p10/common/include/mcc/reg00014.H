/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00014.H $          */
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

#ifndef __MCC_REG00014_H_
#define __MCC_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[CRYPTO_ENCRYPT_CRYPTOKEY2B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOKEY2B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CRYPTO_ENCRYPT_CRYPTOKEY2B]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOKEY2B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOKEY2B;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY2B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOKEY2B]

//>> PUT_[CRYPTO_ENCRYPT_CRYPTOKEY2B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY2B));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY2B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CRYPTO_ENCRYPT_CRYPTOKEY2B]


//>> SET_[CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY2B));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY2B));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY2B));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B]

//>> PREP_[USTL_USTLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[USTL_USTLFIRACT1]

//>> GET_[USTL_USTLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRACT1;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[USTL_USTLFIRACT1]

//>> PUT_[USTL_USTLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIRACT1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT1));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[USTL_USTLFIRACT1]


//>> SET_[USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT1));
#endif
    return o_data.insertFromRight<USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1,
           USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1]

//>> SET_[USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT1));
#endif
    return o_data.insertFromRight<USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1,
           USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1]

//>> GET_[USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT1));
#endif
    return i_data.extractToRight<USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1,
           USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1]

//>> PREP_[USTL_USTLINJ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLINJ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[USTL_USTLINJ]

//>> GET_[USTL_USTLINJ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLINJ;
#endif
    return fapi2::getScom(i_target, USTL_USTLINJ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[USTL_USTLINJ]

//>> PUT_[USTL_USTLINJ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return fapi2::putScom(i_target, USTL_USTLINJ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[USTL_USTLINJ]


//>> SET_[USTL_USTLINJ_FAIL_RESP_TYPE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FAIL_RESP_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FAIL_RESP_TYPE,
           USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_FAIL_RESP_TYPE]

//>> SET_[USTL_USTLINJ_FAIL_RESP_TYPE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FAIL_RESP_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FAIL_RESP_TYPE,
           USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_FAIL_RESP_TYPE]

//>> GET_[USTL_USTLINJ_FAIL_RESP_TYPE]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_FAIL_RESP_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_FAIL_RESP_TYPE,
           USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_FAIL_RESP_TYPE]

//>> SET_[USTL_USTLINJ_FIR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FIR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FIR_INJECT,
           USTL_USTLINJ_FIR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_FIR_INJECT]

//>> SET_[USTL_USTLINJ_FIR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FIR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FIR_INJECT,
           USTL_USTLINJ_FIR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_FIR_INJECT]

//>> GET_[USTL_USTLINJ_FIR_INJECT]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_FIR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_FIR_INJECT,
           USTL_USTLINJ_FIR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_FIR_INJECT]

//>> SET_[USTL_USTLINJ_US_DATA]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA,
           USTL_USTLINJ_US_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_US_DATA]

//>> SET_[USTL_USTLINJ_US_DATA]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA,
           USTL_USTLINJ_US_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_US_DATA]

//>> GET_[USTL_USTLINJ_US_DATA]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_US_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_US_DATA,
           USTL_USTLINJ_US_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_US_DATA]

//>> SET_[USTL_USTLINJ_CHAN_SEL]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_CHAN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_CHAN_SEL]

//>> SET_[USTL_USTLINJ_CHAN_SEL]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_CHAN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_CHAN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_CHAN_SEL]

//>> SET_[USTL_USTLINJ_CHAN_SEL]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.setBit<USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_CHAN_SEL]

//>> CLEAR_[USTL_USTLINJ_CHAN_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.clearBit<USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLINJ_CHAN_SEL]

//>> GET_[USTL_USTLINJ_CHAN_SEL]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_CHAN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_CHAN_SEL]

//>> GET_[USTL_USTLINJ_CHAN_SEL]
static inline bool GET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.getBit<USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_CHAN_SEL]

//>> SET_[USTL_USTLINJ_US_DATA_ERR_EN]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA_ERR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_US_DATA_ERR_EN]

//>> SET_[USTL_USTLINJ_US_DATA_ERR_EN]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA_ERR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA_ERR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_US_DATA_ERR_EN]

//>> SET_[USTL_USTLINJ_US_DATA_ERR_EN]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.setBit<USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_US_DATA_ERR_EN]

//>> CLEAR_[USTL_USTLINJ_US_DATA_ERR_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.clearBit<USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLINJ_US_DATA_ERR_EN]

//>> GET_[USTL_USTLINJ_US_DATA_ERR_EN]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_US_DATA_ERR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_US_DATA_ERR_EN]

//>> GET_[USTL_USTLINJ_US_DATA_ERR_EN]
static inline bool GET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.getBit<USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_US_DATA_ERR_EN]

//>> SET_[USTL_USTLINJ_ONE_SHOT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_ONE_SHOT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_ONE_SHOT]

//>> SET_[USTL_USTLINJ_ONE_SHOT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_ONE_SHOT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_ONE_SHOT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_ONE_SHOT]

//>> SET_[USTL_USTLINJ_ONE_SHOT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.setBit<USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_ONE_SHOT]

//>> CLEAR_[USTL_USTLINJ_ONE_SHOT]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.clearBit<USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLINJ_ONE_SHOT]

//>> GET_[USTL_USTLINJ_ONE_SHOT]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_ONE_SHOT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_ONE_SHOT]

//>> GET_[USTL_USTLINJ_ONE_SHOT]
static inline bool GET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.getBit<USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_ONE_SHOT]

//>> SET_[USTL_USTLINJ_DATA_OUT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_DATA_OUT]

//>> SET_[USTL_USTLINJ_DATA_OUT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_DATA_OUT]

//>> SET_[USTL_USTLINJ_DATA_OUT]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.setBit<USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_DATA_OUT]

//>> CLEAR_[USTL_USTLINJ_DATA_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.clearBit<USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLINJ_DATA_OUT]

//>> GET_[USTL_USTLINJ_DATA_OUT]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_DATA_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_DATA_OUT]

//>> GET_[USTL_USTLINJ_DATA_OUT]
static inline bool GET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.getBit<USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_DATA_OUT]

//>> SET_[USTL_USTLINJ_DATA_DW_SEL]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_DW_SEL,
           USTL_USTLINJ_DATA_DW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_DATA_DW_SEL]

//>> SET_[USTL_USTLINJ_DATA_DW_SEL]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_DW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_DW_SEL,
           USTL_USTLINJ_DATA_DW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLINJ_DATA_DW_SEL]

//>> GET_[USTL_USTLINJ_DATA_DW_SEL]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLINJ));
#endif
    return i_data.extractToRight<USTL_USTLINJ_DATA_DW_SEL,
           USTL_USTLINJ_DATA_DW_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLINJ_DATA_DW_SEL]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
