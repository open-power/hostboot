/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00014.H $          */
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

#ifndef __MCC_REG00014_H_
#define __MCC_REG00014_H_

namespace scomt
{
namespace mcc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f75;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f75;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY2B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f75));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY2B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f75));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f75));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f75));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_MASK_REG_SCOM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011003;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_MASK_REG_SCOM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011003;
#endif
    return fapi2::getScom(i_target, FIR_MASK_REG_SCOM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_MASK_REG_SCOM(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return fapi2::putScom(i_target, FIR_MASK_REG_SCOM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_MASK_REG_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011004;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_MASK_REG_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011004;
#endif
    return fapi2::getScom(i_target, FIR_MASK_REG_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_MASK_REG_SCOM1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return fapi2::putScom(i_target, FIR_MASK_REG_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_MASK_REG_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011005;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_MASK_REG_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc011005;
#endif
    return fapi2::getScom(i_target, FIR_MASK_REG_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_MASK_REG_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return fapi2::putScom(i_target, FIR_MASK_REG_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_OP_IRQ_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_OP_IRQ_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_OP_IRQ_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_OP_IRQ_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_CRC_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_CRC_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_CRC_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_CRC_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_SL_ECC_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_SL_ECC_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SW_RETRAIN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_SW_RETRAIN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SW_RETRAIN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_SW_RETRAIN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NUM_REPLAY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_NUM_REPLAY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NUM_REPLAY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_NUM_REPLAY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NO_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_NO_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NO_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_NO_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SPARE_DONE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_SPARE_DONE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SPARE_DONE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_SPARE_DONE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_OSC_SWITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_OSC_SWITCH_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_OSC_SWITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_OSC_SWITCH_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.insertFromRight<FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.setBit<FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return o_data.clearBit<FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.extractToRight<FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc011005, 0xc011004, 0xc011003));
#endif
    return i_data.getBit<FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PRX0_DLR_APOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc01103a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PRX0_DLR_APOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc01103a;
#endif
    return fapi2::getScom(i_target, REGS_PRX0_DLR_APOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PRX0_DLR_APOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc01103a));
#endif
    return fapi2::putScom(i_target, REGS_PRX0_DLR_APOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc01103a));
#endif
    return o_data.insertFromRight<REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM,
           REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc01103a));
#endif
    return o_data.insertFromRight<REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM,
           REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc01103a));
#endif
    return i_data.extractToRight<REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM,
           REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PRX0_DLR_APOR_BASE_ACCUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc01103a));
#endif
    return o_data.insertFromRight<REGS_PRX0_DLR_APOR_BASE_ACCUM,
           REGS_PRX0_DLR_APOR_BASE_ACCUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PRX0_DLR_APOR_BASE_ACCUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PRX0_DLR_APOR_BASE_ACCUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc01103a));
#endif
    return o_data.insertFromRight<REGS_PRX0_DLR_APOR_BASE_ACCUM,
           REGS_PRX0_DLR_APOR_BASE_ACCUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PRX0_DLR_APOR_BASE_ACCUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PRX0_DLR_APOR_BASE_ACCUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc01103a));
#endif
    return i_data.extractToRight<REGS_PRX0_DLR_APOR_BASE_ACCUM,
           REGS_PRX0_DLR_APOR_BASE_ACCUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PRX0_DLR_APOR_BASE_ACCUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e0c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010e0c;
#endif
    return fapi2::getScom(i_target, USTL_USTLINJ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLINJ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return fapi2::putScom(i_target, USTL_USTLINJ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FAIL_RESP_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FAIL_RESP_TYPE,
           USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FAIL_RESP_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FAIL_RESP_TYPE,
           USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_FAIL_RESP_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_FAIL_RESP_TYPE,
           USTL_USTLINJ_FAIL_RESP_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_FAIL_RESP_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FIR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FIR_INJECT,
           USTL_USTLINJ_FIR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_FIR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_FIR_INJECT,
           USTL_USTLINJ_FIR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_FIR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_FIR_INJECT,
           USTL_USTLINJ_FIR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_FIR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA,
           USTL_USTLINJ_US_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA,
           USTL_USTLINJ_US_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_US_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_US_DATA,
           USTL_USTLINJ_US_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_CHAN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_CHAN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_CHAN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.setBit<USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.clearBit<USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_CHAN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLINJ_CHAN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.getBit<USTL_USTLINJ_CHAN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_CHAN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_DW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_DW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_DW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.setBit<USTL_USTLINJ_DATA_DW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.clearBit<USTL_USTLINJ_DATA_DW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_DATA_DW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLINJ_DATA_DW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.getBit<USTL_USTLINJ_DATA_DW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_DW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA_ERR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA_ERR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_US_DATA_ERR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.setBit<USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.clearBit<USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_US_DATA_ERR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLINJ_US_DATA_ERR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.getBit<USTL_USTLINJ_US_DATA_ERR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_US_DATA_ERR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_ONE_SHOT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_ONE_SHOT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_ONE_SHOT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.setBit<USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.clearBit<USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_ONE_SHOT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLINJ_ONE_SHOT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.getBit<USTL_USTLINJ_ONE_SHOT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_ONE_SHOT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.insertFromRight<USTL_USTLINJ_DATA_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.setBit<USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return o_data.clearBit<USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.extractToRight<USTL_USTLINJ_DATA_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLINJ_DATA_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010e0c));
#endif
    return i_data.getBit<USTL_USTLINJ_DATA_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLINJ_DATA_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
