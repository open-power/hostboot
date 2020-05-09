/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00007.H $         */
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

#ifndef __NMMU_REG00007_H_
#define __NMMU_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


//>> PREP_[CFG_NMMU_CTL_SLB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CFG_NMMU_CTL_SLB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_CTL_SLB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CFG_NMMU_CTL_SLB]

//>> GET_[CFG_NMMU_CTL_SLB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CFG_NMMU_CTL_SLB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_CTL_SLB;
#endif
    return fapi2::getScom(i_target, CFG_NMMU_CTL_SLB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB]

//>> PUT_[CFG_NMMU_CTL_SLB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CFG_NMMU_CTL_SLB(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return fapi2::putScom(i_target, CFG_NMMU_CTL_SLB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CFG_NMMU_CTL_SLB]


//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MBR_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_RESERVED_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_RESERVED_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_RESERVED_31]

//>> SET_[CFG_NMMU_CTL_SLB_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_RESERVED_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_RESERVED_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_RESERVED_31]

//>> SET_[CFG_NMMU_CTL_SLB_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_RESERVED_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_RESERVED_31]

//>> CLEAR_[CFG_NMMU_CTL_SLB_RESERVED_31]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_RESERVED_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_RESERVED_31]

//>> GET_[CFG_NMMU_CTL_SLB_RESERVED_31]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_RESERVED_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_RESERVED_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_RESERVED_31]

//>> GET_[CFG_NMMU_CTL_SLB_RESERVED_31]
static inline bool GET_CFG_NMMU_CTL_SLB_RESERVED_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_RESERVED_31]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL,
           CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL]

//>> SET_[CFG_NMMU_CTL_SLB_RESERVED_40_51]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_RESERVED_40_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_RESERVED_40_51,
           CFG_NMMU_CTL_SLB_RESERVED_40_51_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_40_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_RESERVED_40_51]

//>> SET_[CFG_NMMU_CTL_SLB_RESERVED_40_51]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_RESERVED_40_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_RESERVED_40_51,
           CFG_NMMU_CTL_SLB_RESERVED_40_51_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_40_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_RESERVED_40_51]

//>> GET_[CFG_NMMU_CTL_SLB_RESERVED_40_51]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_RESERVED_40_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_RESERVED_40_51,
           CFG_NMMU_CTL_SLB_RESERVED_40_51_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_40_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_RESERVED_40_51]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS]

//>> SET_[CFG_NMMU_CTL_SLB_RESERVED_53_56]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_RESERVED_53_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_RESERVED_53_56,
           CFG_NMMU_CTL_SLB_RESERVED_53_56_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_53_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_RESERVED_53_56]

//>> SET_[CFG_NMMU_CTL_SLB_RESERVED_53_56]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_RESERVED_53_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_RESERVED_53_56,
           CFG_NMMU_CTL_SLB_RESERVED_53_56_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_53_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_RESERVED_53_56]

//>> GET_[CFG_NMMU_CTL_SLB_RESERVED_53_56]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_RESERVED_53_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_RESERVED_53_56,
           CFG_NMMU_CTL_SLB_RESERVED_53_56_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_RESERVED_53_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_RESERVED_53_56]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]

//>> SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]

//>> CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]

//>> GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]
static inline bool GET_CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SLB));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_CTL_SLB_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA]

//>> PREP_[CFG_NMMU_XLAT_CTL_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CFG_NMMU_XLAT_CTL_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_XLAT_CTL_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CFG_NMMU_XLAT_CTL_REG2]

//>> GET_[CFG_NMMU_XLAT_CTL_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CFG_NMMU_XLAT_CTL_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_XLAT_CTL_REG2;
#endif
    return fapi2::getScom(i_target, CFG_NMMU_XLAT_CTL_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CFG_NMMU_XLAT_CTL_REG2]

//>> PUT_[CFG_NMMU_XLAT_CTL_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CFG_NMMU_XLAT_CTL_REG2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG2));
#endif
    return fapi2::putScom(i_target, CFG_NMMU_XLAT_CTL_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CFG_NMMU_XLAT_CTL_REG2]


//>> SET_[CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG2));
#endif
    return o_data.insertFromRight<CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR,
           CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR]

//>> SET_[CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR]
static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG2));
#endif
    return o_data.insertFromRight<CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR,
           CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR]

//>> GET_[CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR]
static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG2));
#endif
    return i_data.extractToRight<CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR,
           CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR]

//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG]


//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0]

//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG]


//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
