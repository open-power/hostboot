/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00008.H $          */
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

#ifndef __MCC_REG00008_H_
#define __MCC_REG00008_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[USTL_USTLFIRACT0]
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
//<< PREP_[USTL_USTLFIRACT0]

//>> GET_[USTL_USTLFIRACT0]
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
//<< GET_[USTL_USTLFIRACT0]

//>> PUT_[USTL_USTLFIRACT0]
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
//<< PUT_[USTL_USTLFIRACT0]


//>> SET_[USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0]

//>> SET_[USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0]

//>> GET_[USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0]

//>> PREP_[ATCL_CL_CLSCOM_MCEPSQ]
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
//<< PREP_[ATCL_CL_CLSCOM_MCEPSQ]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ]
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
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ]

//>> PUT_[ATCL_CL_CLSCOM_MCEPSQ]
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
//<< PUT_[ATCL_CL_CLSCOM_MCEPSQ]


//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON]

//>> SET_[ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON]

//>> GET_[ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON]

//>> PREP_[CRYPTO_ENCRYPT_CRYPTOCFG]
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
//<< PREP_[CRYPTO_ENCRYPT_CRYPTOCFG]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG]
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
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG]

//>> PUT_[CRYPTO_ENCRYPT_CRYPTOCFG]
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
//<< PUT_[CRYPTO_ENCRYPT_CRYPTOCFG]


//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline bool GET_CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE]

//>> PREP_[CRYPTO_DECRYPT_CRYPTOKEY2B]
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
//<< PREP_[CRYPTO_DECRYPT_CRYPTOKEY2B]

//>> GET_[CRYPTO_DECRYPT_CRYPTOKEY2B]
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
//<< GET_[CRYPTO_DECRYPT_CRYPTOKEY2B]

//>> PUT_[CRYPTO_DECRYPT_CRYPTOKEY2B]
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
//<< PUT_[CRYPTO_DECRYPT_CRYPTOKEY2B]


//>> SET_[CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B]

//>> SET_[CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B]

//>> GET_[CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
