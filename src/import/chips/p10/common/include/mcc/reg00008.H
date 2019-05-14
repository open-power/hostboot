/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00008.H $          */
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

#ifndef __MCC_REG00008_H_
#define __MCC_REG00008_H_

namespace scomt
{
namespace mcc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCEPSQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCEPSQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCEPSQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCEPSQ;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCEPSQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCEPSQ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCEPSQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCEPSQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON,
           ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY2B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY2B;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY2B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTOKEY2B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2B));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY2B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2B));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2B));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY2B));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B,
           CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTOCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTOCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOCFG;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTOCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTOCFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTOCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11,
           CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11,
           CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11,
           CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ,
           CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE,
           CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE,
           CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE,
           CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLBADRESP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLBADRESP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLBADRESP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLBADRESP;
#endif
    return fapi2::getScom(i_target, USTL_USTLBADRESP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLBADRESP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return fapi2::putScom(i_target, USTL_USTLBADRESP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.setBit<USTL_USTLBADRESP_A_BAD_RESP_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLBADRESP_A_BAD_RESP_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.clearBit<USTL_USTLBADRESP_A_BAD_RESP_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_A_BAD_RESP_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_A_BAD_RESP_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLBADRESP_A_BAD_RESP_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.getBit<USTL_USTLBADRESP_A_BAD_RESP_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.setBit<USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.clearBit<USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.getBit<USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.setBit<USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.clearBit<USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.getBit<USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_TAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_TAG,
           USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_A_BAD_RESP_TAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_A_BAD_RESP_TAG,
           USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_A_BAD_RESP_TAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_A_BAD_RESP_TAG,
           USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_A_BAD_RESP_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.setBit<USTL_USTLBADRESP_B_BAD_RESP_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLBADRESP_B_BAD_RESP_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.clearBit<USTL_USTLBADRESP_B_BAD_RESP_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_B_BAD_RESP_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_B_BAD_RESP_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLBADRESP_B_BAD_RESP_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.getBit<USTL_USTLBADRESP_B_BAD_RESP_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.setBit<USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.clearBit<USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.getBit<USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.setBit<USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.clearBit<USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.getBit<USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_TAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_TAG,
           USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLBADRESP_B_BAD_RESP_TAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return o_data.insertFromRight<USTL_USTLBADRESP_B_BAD_RESP_TAG,
           USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLBADRESP_B_BAD_RESP_TAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLBADRESP));
#endif
    return i_data.extractToRight<USTL_USTLBADRESP_B_BAD_RESP_TAG,
           USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLBADRESP_B_BAD_RESP_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLERRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLERRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLERRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLERRPT;
#endif
    return fapi2::getScom(i_target, USTL_USTLERRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLERRPT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return fapi2::putScom(i_target, USTL_USTLERRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_CMT_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_CMT_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_CMT_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.setBit<USTL_USTLERRPT_WDF_CMT_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.clearBit<USTL_USTLERRPT_WDF_CMT_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRPT_WDF_CMT_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRPT_WDF_CMT_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.getBit<USTL_USTLERRPT_WDF_CMT_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMT_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_CMD_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_CMD_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_CMD_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.setBit<USTL_USTLERRPT_WDF_CMD_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.clearBit<USTL_USTLERRPT_WDF_CMD_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRPT_WDF_CMD_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRPT_WDF_CMD_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.getBit<USTL_USTLERRPT_WDF_CMD_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_CMD_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WRT_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WRT_NO_BUFF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WRT_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.setBit<USTL_USTLERRPT_WRT_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.clearBit<USTL_USTLERRPT_WRT_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRPT_WRT_NO_BUFF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRPT_WRT_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.getBit<USTL_USTLERRPT_WRT_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.setBit<USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.clearBit<USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.getBit<USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.setBit<USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.clearBit<USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.getBit<USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_NO_BUFF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_WDF_NO_BUFF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.setBit<USTL_USTLERRPT_WDF_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.clearBit<USTL_USTLERRPT_WDF_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRPT_WDF_NO_BUFF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLERRPT_WDF_NO_BUFF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.getBit<USTL_USTLERRPT_WDF_NO_BUFF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_WDF_NO_BUFF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_RESERVED,
           USTL_USTLERRPT_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLERRPT_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return o_data.insertFromRight<USTL_USTLERRPT_RESERVED,
           USTL_USTLERRPT_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLERRPT_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLERRPT));
#endif
    return i_data.extractToRight<USTL_USTLERRPT_RESERVED,
           USTL_USTLERRPT_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLERRPT_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRACT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRACT0;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIRACT0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT0));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT0));
#endif
    return o_data.insertFromRight<USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0,
           USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT0));
#endif
    return o_data.insertFromRight<USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0,
           USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT0));
#endif
    return i_data.extractToRight<USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0,
           USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLSTATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLSTATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLSTATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLSTATUS;
#endif
    return fapi2::getScom(i_target, USTL_USTLSTATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLSTATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return fapi2::putScom(i_target, USTL_USTLSTATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_LOL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_LOL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_LOL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_LOL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_LOL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LOL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_FAIL_RESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_FAIL_RESP,
           USTL_USTLSTATUS_FAIL_RESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_FAIL_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_FAIL_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_FAIL_RESP,
           USTL_USTLSTATUS_FAIL_RESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_FAIL_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_FAIL_RESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_FAIL_RESP,
           USTL_USTLSTATUS_FAIL_RESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_FAIL_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS,
           USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS,
           USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS,
           USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS,
           USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS,
           USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS,
           USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_WAT_FIRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_WAT_FIRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_WAT_FIRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_WAT_FIRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_WAT_FIRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_WAT_FIRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_WAT_FIRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_WAT_FIRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_WAT_FIRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.insertFromRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.setBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return o_data.clearBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.extractToRight<USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLSTATUS));
#endif
    return i_data.getBit<USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WDF_WDFDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WDF_WDFDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WDF_WDFDBG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WDF_WDFDBG;
#endif
    return fapi2::getScom(i_target, WDF_WDFDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WDF_WDFDBG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return fapi2::putScom(i_target, WDF_WDFDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_DBG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_DBG_SPARE,
           WDF_WDFDBG_DBG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_DBG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_DBG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_DBG_SPARE,
           WDF_WDFDBG_DBG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_DBG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFDBG_DBG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return i_data.extractToRight<WDF_WDFDBG_DBG_SPARE,
           WDF_WDFDBG_DBG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_DBG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT_EVENT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT_EVENT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_EVENT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT_EVENT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT_EVENT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_EVENT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT_EVENT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.setBit<WDF_WDFDBG_WAT_EVENT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_EVENT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WDF_WDFDBG_WAT_EVENT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.clearBit<WDF_WDFDBG_WAT_EVENT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_EVENT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFDBG_WAT_EVENT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return i_data.extractToRight<WDF_WDFDBG_WAT_EVENT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_EVENT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WDF_WDFDBG_WAT_EVENT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return i_data.getBit<WDF_WDFDBG_WAT_EVENT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_EVENT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT_SPARE1,
           WDF_WDFDBG_WAT_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT_SPARE1,
           WDF_WDFDBG_WAT_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFDBG_WAT_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return i_data.extractToRight<WDF_WDFDBG_WAT_SPARE1,
           WDF_WDFDBG_WAT_SPARE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT0_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT0_EVENT_SELECT,
           WDF_WDFDBG_WAT0_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT0_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT0_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT0_EVENT_SELECT,
           WDF_WDFDBG_WAT0_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT0_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFDBG_WAT0_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return i_data.extractToRight<WDF_WDFDBG_WAT0_EVENT_SELECT,
           WDF_WDFDBG_WAT0_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT0_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT1_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT1_EVENT_SELECT,
           WDF_WDFDBG_WAT1_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT1_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WDF_WDFDBG_WAT1_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return o_data.insertFromRight<WDF_WDFDBG_WAT1_EVENT_SELECT,
           WDF_WDFDBG_WAT1_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT1_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WDF_WDFDBG_WAT1_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WDF_WDFDBG));
#endif
    return i_data.extractToRight<WDF_WDFDBG_WAT1_EVENT_SELECT,
           WDF_WDFDBG_WAT1_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WDF_WDFDBG_WAT1_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
