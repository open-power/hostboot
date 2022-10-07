/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00021.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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

#ifndef __PROC_REG00021_H_
#define __PROC_REG00021_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_PC_REGS_TCTXT_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_TCTXT_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_PC_REGS_TCTXT_CFG]

//>> GET_[INT_PC_REGS_TCTXT_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_TCTXT_CFG;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG]

//>> PUT_[INT_PC_REGS_TCTXT_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_PC_REGS_TCTXT_CFG]


//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_FUSE_CORE_EN]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_PHYP_CORE_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_2_3,
           INT_PC_REGS_TCTXT_CFG_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_2_3,
           INT_PC_REGS_TCTXT_CFG_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_2_3,
           INT_PC_REGS_TCTXT_CFG_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_2_3]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_HYP_TARGET_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_GEN1_OS_ST_ACK]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_TCTXT_OGEN_FINE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_7_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_7_11,
           INT_PC_REGS_TCTXT_CFG_RESERVED_7_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_7_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_7_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_7_11,
           INT_PC_REGS_TCTXT_CFG_RESERVED_7_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_7_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_7_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_7_11,
           INT_PC_REGS_TCTXT_CFG_RESERVED_7_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_7_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_7_11]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_EBB_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_EARLY_CRESP_VP_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_14_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_14_16,
           INT_PC_REGS_TCTXT_CFG_RESERVED_14_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_14_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_14_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_14_16,
           INT_PC_REGS_TCTXT_CFG_RESERVED_14_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_14_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_14_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_14_16,
           INT_PC_REGS_TCTXT_CFG_RESERVED_14_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_14_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_14_16]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_INT_MSGSND_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_18_19,
           INT_PC_REGS_TCTXT_CFG_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_18_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_18_19,
           INT_PC_REGS_TCTXT_CFG_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_18_19,
           INT_PC_REGS_TCTXT_CFG_RESERVED_18_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_18_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_18_19]

//>> SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> CLEAR_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]
static inline bool GET_INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_HOSTBOOT_MODE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_21_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_21_24,
           INT_PC_REGS_TCTXT_CFG_RESERVED_21_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_21_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]

//>> SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_RESERVED_21_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_RESERVED_21_24,
           INT_PC_REGS_TCTXT_CFG_RESERVED_21_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_21_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]

//>> GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_RESERVED_21_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_RESERVED_21_24,
           INT_PC_REGS_TCTXT_CFG_RESERVED_21_24_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_RESERVED_21_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_RESERVED_21_24]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS,
           INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS,
           INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS,
           INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_COMPLEX_STORE_DIS]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO,
           INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO,
           INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO,
           INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_PCMD_ARB_QUERY_PRIO]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE,
           INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]

//>> SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE,
           INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]

//>> GET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_CFG));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE,
           INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_REGS_TCTXT_CFG_CFG_LGS_AGE]

//>> PREP_[INT_VC_ENDC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_VC_ENDC_FLUSH_CTRL]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_CTRL;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_FLUSH_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL]

//>> PUT_[INT_VC_ENDC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_FLUSH_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_VC_ENDC_FLUSH_CTRL]


//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6,
           INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6,
           INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6,
           INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_RESERVED_4_6]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> CLEAR_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline bool GET_INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ENDC_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_MEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_MEM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_MEM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_MEM]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_MEM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_MEM;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_MEM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_MEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_MEM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_MEM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_MEM]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SPARE67]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_BASE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_BASE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_BASE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_BASE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_BASE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_BASE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_BASE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MEM_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MEM_BASE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_BASE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MEM));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE,
           PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_TRIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_TRIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_TRIG]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_TRIG;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_TRIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_TRIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_TRIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_TRIG]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_START]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_PAUSE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_STOP_ALT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_RESET]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_VALID]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE,
           PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE,
           PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TRIG));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE,
           PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TRIG_MARK_TYPE]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK,
           PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_EQ0]

//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_ES3]

//>> PREP_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW]

//>> PUT_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW]

//>> PREP_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND]

//>> PUT_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND]

//>> PREP_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR]

//>> PUT_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR]


//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_3_MASK]

//>> SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]

//>> SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]

//>> SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]

//>> CLEAR_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]

//>> GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]

//>> GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]
static inline bool GET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_INACTIVE_LINK_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_COHERENCY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ADDR_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_CRESP_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_LIMIT_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_SPARE_8_MASK]

//>> SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]

//>> SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]

//>> SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]

//>> CLEAR_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]

//>> GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]

//>> GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]
static inline bool GET_P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_ACTIVE_LINK_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FORCE_MP_IPL_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_PB_CMD_SNOOPER_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_DATA_ROUTE_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_FIR_COMPAB_TRIGGER_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK0_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_PROTOCOL_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_OVERFLOW_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]

//>> SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]

//>> GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_RW, PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_LINK1_HW_PARITY_ERROR_MASK]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
