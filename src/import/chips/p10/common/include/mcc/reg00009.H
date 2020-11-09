/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00009.H $          */
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

#ifndef __MCC_REG00009_H_
#define __MCC_REG00009_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[DSTL_DSTLFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DSTL_DSTLFIRMASK_RW]

//>> GET_[DSTL_DSTLFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_RW;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DSTL_DSTLFIRMASK_RW]

//>> PUT_[DSTL_DSTLFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DSTL_DSTLFIRMASK_RW]

//>> PREP_[DSTL_DSTLFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DSTL_DSTLFIRMASK_WO_AND]

//>> GET_[DSTL_DSTLFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DSTL_DSTLFIRMASK_WO_AND]

//>> PUT_[DSTL_DSTLFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DSTL_DSTLFIRMASK_WO_AND]

//>> PREP_[DSTL_DSTLFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DSTL_DSTLFIRMASK_WO_OR]

//>> GET_[DSTL_DSTLFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DSTL_DSTLFIRMASK_WO_OR]

//>> PUT_[DSTL_DSTLFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DSTL_DSTLFIRMASK_WO_OR]


//>> SET_[DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]

//>> SET_[DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]

//>> GET_[DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]

//>> SET_[P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]

//>> SET_[P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]

//>> GET_[P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRMASK_RW, DSTL_DSTLFIRMASK_WO_AND, DSTL_DSTLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK,
           P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK]

//>> PREP_[WRITE_WRTCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_WRTCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRTCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[WRITE_WRTCFG]

//>> GET_[WRITE_WRTCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_WRTCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRTCFG;
#endif
    return fapi2::getScom(i_target, WRITE_WRTCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[WRITE_WRTCFG]

//>> PUT_[WRITE_WRTCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_WRTCFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return fapi2::putScom(i_target, WRITE_WRTCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[WRITE_WRTCFG]


//>> SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> CLEAR_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline bool GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> CLEAR_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline bool GET_WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[WRITE_WRTCFG_RESERVED_2_8]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_2_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_2_8,
           WRITE_WRTCFG_RESERVED_2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_2_8]

//>> SET_[WRITE_WRTCFG_RESERVED_2_8]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_2_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_2_8,
           WRITE_WRTCFG_RESERVED_2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_2_8]

//>> GET_[WRITE_WRTCFG_RESERVED_2_8]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_2_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_2_8,
           WRITE_WRTCFG_RESERVED_2_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_2_8]

//>> SET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_NEW_WRITE_64B_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]

//>> SET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_NEW_WRITE_64B_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]

//>> SET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_NEW_WRITE_64B_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]

//>> CLEAR_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_NEW_WRITE_64B_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]

//>> GET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_NEW_WRITE_64B_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]

//>> GET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]
static inline bool GET_WRITE_WRTCFG_NEW_WRITE_64B_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_NEW_WRITE_64B_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_WRTCFG_NEW_WRITE_64B_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_NEW_WRITE_64B_MODE]

//>> SET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]

//>> SET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]

//>> SET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]

//>> CLEAR_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]

//>> GET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]

//>> GET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]
static inline bool GET_WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE]

//>> SET_[WRITE_WRTCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_11]

//>> SET_[WRITE_WRTCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_11]

//>> SET_[WRITE_WRTCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_11]

//>> CLEAR_[WRITE_WRTCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_WRTCFG_RESERVED_11]

//>> GET_[WRITE_WRTCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_11]

//>> GET_[WRITE_WRTCFG_RESERVED_11]
static inline bool GET_WRITE_WRTCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_11]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_DW0_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_DW1_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_DW2_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ,
           WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_DW3_ERR_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]

//>> CLEAR_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]
static inline bool GET_WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_ONE_SHOT_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.setBit<WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]

//>> CLEAR_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.clearBit<WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]

//>> GET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]
static inline bool GET_WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.getBit<WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_DSTL_PERSISTANT_INJ]

//>> SET_[WRITE_WRTCFG_RESERVED_22_31]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_22_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_22_31,
           WRITE_WRTCFG_RESERVED_22_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_22_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_22_31]

//>> SET_[WRITE_WRTCFG_RESERVED_22_31]
static inline fapi2::buffer<uint64_t>& SET_WRITE_WRTCFG_RESERVED_22_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return o_data.insertFromRight<WRITE_WRTCFG_RESERVED_22_31,
           WRITE_WRTCFG_RESERVED_22_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_22_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_WRTCFG_RESERVED_22_31]

//>> GET_[WRITE_WRTCFG_RESERVED_22_31]
static inline fapi2::buffer<uint64_t>& GET_WRITE_WRTCFG_RESERVED_22_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRTCFG));
#endif
    return i_data.extractToRight<WRITE_WRTCFG_RESERVED_22_31,
           WRITE_WRTCFG_RESERVED_22_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_WRTCFG_RESERVED_22_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_WRTCFG_RESERVED_22_31]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
