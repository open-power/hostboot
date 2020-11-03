/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00031.H $         */
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

#ifndef __PROC_REG00031_H_
#define __PROC_REG00031_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[NX_DMA_SU_CRB_KILL_REQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_SU_CRB_KILL_REQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SU_CRB_KILL_REQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_DMA_SU_CRB_KILL_REQ]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_SU_CRB_KILL_REQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SU_CRB_KILL_REQ;
#endif
    return fapi2::getScom(i_target, NX_DMA_SU_CRB_KILL_REQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ]

//>> PUT_[NX_DMA_SU_CRB_KILL_REQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_SU_CRB_KILL_REQ(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return fapi2::putScom(i_target, NX_DMA_SU_CRB_KILL_REQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_DMA_SU_CRB_KILL_REQ]


//>> SET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.setBit<NX_DMA_SU_CRB_KILL_REQ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]

//>> CLEAR_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.clearBit<NX_DMA_SU_CRB_KILL_REQ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]
static inline bool GET_NX_DMA_SU_CRB_KILL_REQ_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.getBit<NX_DMA_SU_CRB_KILL_REQ_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_ENABLE]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_DONE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_DONE]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_DONE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_DONE]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_DONE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.setBit<NX_DMA_SU_CRB_KILL_REQ_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_DONE]

//>> CLEAR_[NX_DMA_SU_CRB_KILL_REQ_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.clearBit<NX_DMA_SU_CRB_KILL_REQ_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_CRB_KILL_REQ_DONE]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_DONE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_DONE]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_DONE]
static inline bool GET_NX_DMA_SU_CRB_KILL_REQ_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.getBit<NX_DMA_SU_CRB_KILL_REQ_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_DONE]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SUMMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SUMMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.setBit<NX_DMA_SU_CRB_KILL_REQ_SUMMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]

//>> CLEAR_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.clearBit<NX_DMA_SU_CRB_KILL_REQ_SUMMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_SUMMARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]
static inline bool GET_NX_DMA_SU_CRB_KILL_REQ_SUMMARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.getBit<NX_DMA_SU_CRB_KILL_REQ_SUMMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SUMMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_SUMMARY]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT,
           NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT,
           NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT,
           NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT,
           NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE,
           NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE]

//>> SET_[NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return o_data.insertFromRight<NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE,
           NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE]

//>> GET_[NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_CRB_KILL_REQ));
#endif
    return i_data.extractToRight<NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE,
           NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM0_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM0_LAST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM0_LAST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM0_LAST]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM0_LAST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM0_LAST;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM0_LAST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM0_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM0_LAST(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM0_LAST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM0_LAST]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_EQ0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
