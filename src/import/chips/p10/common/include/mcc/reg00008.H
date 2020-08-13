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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
