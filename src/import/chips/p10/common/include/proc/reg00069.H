/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00069.H $         */
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

#ifndef __PROC_REG00069_H_
#define __PROC_REG00069_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[VAS_VA_RG_SCF_MISCCTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_MISCCTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_MISCCTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_MISCCTL]

//>> GET_[VAS_VA_RG_SCF_MISCCTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_MISCCTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_MISCCTL;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_MISCCTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL]

//>> PUT_[VAS_VA_RG_SCF_MISCCTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_MISCCTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_MISCCTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_MISCCTL]


//>> SET_[VAS_VA_RG_SCF_MISCCTL_4VS64]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_4VS64(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_4VS64,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_4VS64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_4VS64]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_4VS64]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_4VS64(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_4VS64,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_4VS64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_4VS64]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_4VS64]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_4VS64(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_4VS64>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_4VS64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_4VS64]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_4VS64]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_4VS64(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_4VS64>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_4VS64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_4VS64]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_4VS64]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_4VS64(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_4VS64,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_4VS64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_4VS64]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_4VS64]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_4VS64(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_4VS64>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_4VS64 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_4VS64]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_ACCEPT_PASTE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_ENABLE_WRMON]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_DISABLE_PUSH2MEM_LIMIT]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_QUIESCE_REQUEST]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_PREFETCH_DISABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_WCMBAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_UWCMBAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_RMABAR_ENABLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_LOC]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_INVALIDATE_CAM_ALL]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION,
           VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION,
           VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION,
           VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_CAM_LOCATION]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_CAM_INVAL_DONE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_HMI_ACTIVE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]

//>> SET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]

//>> CLEAR_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]

//>> GET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]
static inline bool GET_VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MISCCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MISCCTL_RG_IS_IDLE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
