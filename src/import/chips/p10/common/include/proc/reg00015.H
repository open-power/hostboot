/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00015.H $         */
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

#ifndef __PROC_REG00015_H_
#define __PROC_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_CQ_NVPG_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_NVPG_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_NVPG_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_CQ_NVPG_BAR]

//>> GET_[INT_CQ_NVPG_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_NVPG_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_NVPG_BAR;
#endif
    return fapi2::getScom(i_target, INT_CQ_NVPG_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR]

//>> PUT_[INT_CQ_NVPG_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_NVPG_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return fapi2::putScom(i_target, INT_CQ_NVPG_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_CQ_NVPG_BAR]


//>> SET_[INT_CQ_NVPG_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVPG_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_VALID]

//>> SET_[INT_CQ_NVPG_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVPG_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_VALID]

//>> SET_[INT_CQ_NVPG_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.setBit<INT_CQ_NVPG_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_NVPG_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_VALID]

//>> CLEAR_[INT_CQ_NVPG_BAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_NVPG_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.clearBit<INT_CQ_NVPG_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_NVPG_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_NVPG_BAR_VALID]

//>> GET_[INT_CQ_NVPG_BAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVPG_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVPG_BAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVPG_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR_VALID]

//>> GET_[INT_CQ_NVPG_BAR_VALID]
static inline bool GET_INT_CQ_NVPG_BAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return i_data.getBit<INT_CQ_NVPG_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_NVPG_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR_VALID]

//>> SET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVPG_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVPG_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.setBit<INT_CQ_NVPG_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_NVPG_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]

//>> CLEAR_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_NVPG_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.clearBit<INT_CQ_NVPG_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_NVPG_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVPG_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVPG_BAR_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVPG_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]
static inline bool GET_INT_CQ_NVPG_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return i_data.getBit<INT_CQ_NVPG_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_NVPG_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_NVPG_BAR_ADDR_8_39]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_ADDR_8_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_ADDR_8_39,
           INT_CQ_NVPG_BAR_ADDR_8_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVPG_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_ADDR_8_39]

//>> SET_[INT_CQ_NVPG_BAR_ADDR_8_39]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_ADDR_8_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_ADDR_8_39,
           INT_CQ_NVPG_BAR_ADDR_8_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVPG_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_ADDR_8_39]

//>> GET_[INT_CQ_NVPG_BAR_ADDR_8_39]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVPG_BAR_ADDR_8_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVPG_BAR_ADDR_8_39,
           INT_CQ_NVPG_BAR_ADDR_8_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVPG_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR_ADDR_8_39]

//>> SET_[INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2]

//>> SET_[INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2]

//>> GET_[INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2]

//>> SET_[INT_CQ_NVPG_BAR_RANGE_0_4]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_RANGE_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_RANGE_0_4,
           INT_CQ_NVPG_BAR_RANGE_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVPG_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_RANGE_0_4]

//>> SET_[INT_CQ_NVPG_BAR_RANGE_0_4]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVPG_BAR_RANGE_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVPG_BAR_RANGE_0_4,
           INT_CQ_NVPG_BAR_RANGE_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVPG_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVPG_BAR_RANGE_0_4]

//>> GET_[INT_CQ_NVPG_BAR_RANGE_0_4]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVPG_BAR_RANGE_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVPG_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVPG_BAR_RANGE_0_4,
           INT_CQ_NVPG_BAR_RANGE_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVPG_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVPG_BAR_RANGE_0_4]

//>> PREP_[INT_CQ_RST_CTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_RST_CTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_RST_CTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_CQ_RST_CTL]

//>> GET_[INT_CQ_RST_CTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_RST_CTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_RST_CTL;
#endif
    return fapi2::getScom(i_target, INT_CQ_RST_CTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_CQ_RST_CTL]

//>> PUT_[INT_CQ_RST_CTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_RST_CTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return fapi2::putScom(i_target, INT_CQ_RST_CTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_CQ_RST_CTL]


//>> SET_[INT_CQ_RST_CTL_SYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_SYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_SYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_RST_CTL_SYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_SYNC_RESET]

//>> SET_[INT_CQ_RST_CTL_SYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_SYNC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_SYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_RST_CTL_SYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_SYNC_RESET]

//>> SET_[INT_CQ_RST_CTL_SYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_SYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.setBit<INT_CQ_RST_CTL_SYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_RST_CTL_SYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_SYNC_RESET]

//>> CLEAR_[INT_CQ_RST_CTL_SYNC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_RST_CTL_SYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.clearBit<INT_CQ_RST_CTL_SYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_RST_CTL_SYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_RST_CTL_SYNC_RESET]

//>> GET_[INT_CQ_RST_CTL_SYNC_RESET]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_RST_CTL_SYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.extractToRight<INT_CQ_RST_CTL_SYNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_RST_CTL_SYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_SYNC_RESET]

//>> GET_[INT_CQ_RST_CTL_SYNC_RESET]
static inline bool GET_INT_CQ_RST_CTL_SYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.getBit<INT_CQ_RST_CTL_SYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_RST_CTL_SYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_SYNC_RESET]

//>> SET_[INT_CQ_RST_CTL_QUIESCE_PB]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_QUIESCE_PB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_QUIESCE_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_RST_CTL_QUIESCE_PB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_QUIESCE_PB]

//>> SET_[INT_CQ_RST_CTL_QUIESCE_PB]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_QUIESCE_PB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_QUIESCE_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_RST_CTL_QUIESCE_PB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_QUIESCE_PB]

//>> SET_[INT_CQ_RST_CTL_QUIESCE_PB]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_QUIESCE_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.setBit<INT_CQ_RST_CTL_QUIESCE_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_RST_CTL_QUIESCE_PB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_QUIESCE_PB]

//>> CLEAR_[INT_CQ_RST_CTL_QUIESCE_PB]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_RST_CTL_QUIESCE_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.clearBit<INT_CQ_RST_CTL_QUIESCE_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_RST_CTL_QUIESCE_PB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_RST_CTL_QUIESCE_PB]

//>> GET_[INT_CQ_RST_CTL_QUIESCE_PB]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_RST_CTL_QUIESCE_PB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.extractToRight<INT_CQ_RST_CTL_QUIESCE_PB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_RST_CTL_QUIESCE_PB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_QUIESCE_PB]

//>> GET_[INT_CQ_RST_CTL_QUIESCE_PB]
static inline bool GET_INT_CQ_RST_CTL_QUIESCE_PB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.getBit<INT_CQ_RST_CTL_QUIESCE_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_RST_CTL_QUIESCE_PB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_QUIESCE_PB]

//>> SET_[INT_CQ_RST_CTL_MASTER_IDLE]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_MASTER_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_MASTER_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_RST_CTL_MASTER_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_MASTER_IDLE]

//>> SET_[INT_CQ_RST_CTL_MASTER_IDLE]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_MASTER_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_MASTER_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_RST_CTL_MASTER_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_MASTER_IDLE]

//>> SET_[INT_CQ_RST_CTL_MASTER_IDLE]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_MASTER_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.setBit<INT_CQ_RST_CTL_MASTER_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_RST_CTL_MASTER_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_MASTER_IDLE]

//>> CLEAR_[INT_CQ_RST_CTL_MASTER_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_RST_CTL_MASTER_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.clearBit<INT_CQ_RST_CTL_MASTER_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_RST_CTL_MASTER_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_RST_CTL_MASTER_IDLE]

//>> GET_[INT_CQ_RST_CTL_MASTER_IDLE]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_RST_CTL_MASTER_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.extractToRight<INT_CQ_RST_CTL_MASTER_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_RST_CTL_MASTER_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_MASTER_IDLE]

//>> GET_[INT_CQ_RST_CTL_MASTER_IDLE]
static inline bool GET_INT_CQ_RST_CTL_MASTER_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.getBit<INT_CQ_RST_CTL_MASTER_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_RST_CTL_MASTER_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_MASTER_IDLE]

//>> SET_[INT_CQ_RST_CTL_SLAVE_IDLE]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_SLAVE_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_SLAVE_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_RST_CTL_SLAVE_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_SLAVE_IDLE]

//>> SET_[INT_CQ_RST_CTL_SLAVE_IDLE]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_SLAVE_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_SLAVE_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_RST_CTL_SLAVE_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_SLAVE_IDLE]

//>> SET_[INT_CQ_RST_CTL_SLAVE_IDLE]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_SLAVE_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.setBit<INT_CQ_RST_CTL_SLAVE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_RST_CTL_SLAVE_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_SLAVE_IDLE]

//>> CLEAR_[INT_CQ_RST_CTL_SLAVE_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_RST_CTL_SLAVE_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.clearBit<INT_CQ_RST_CTL_SLAVE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_RST_CTL_SLAVE_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_RST_CTL_SLAVE_IDLE]

//>> GET_[INT_CQ_RST_CTL_SLAVE_IDLE]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_RST_CTL_SLAVE_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.extractToRight<INT_CQ_RST_CTL_SLAVE_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_RST_CTL_SLAVE_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_SLAVE_IDLE]

//>> GET_[INT_CQ_RST_CTL_SLAVE_IDLE]
static inline bool GET_INT_CQ_RST_CTL_SLAVE_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.getBit<INT_CQ_RST_CTL_SLAVE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_RST_CTL_SLAVE_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_SLAVE_IDLE]

//>> SET_[INT_CQ_RST_CTL_PB_BAR_RESET]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_PB_BAR_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_PB_BAR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_RST_CTL_PB_BAR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_PB_BAR_RESET]

//>> SET_[INT_CQ_RST_CTL_PB_BAR_RESET]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_PB_BAR_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_PB_BAR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_RST_CTL_PB_BAR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_PB_BAR_RESET]

//>> SET_[INT_CQ_RST_CTL_PB_BAR_RESET]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_PB_BAR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.setBit<INT_CQ_RST_CTL_PB_BAR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_RST_CTL_PB_BAR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_PB_BAR_RESET]

//>> CLEAR_[INT_CQ_RST_CTL_PB_BAR_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_RST_CTL_PB_BAR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.clearBit<INT_CQ_RST_CTL_PB_BAR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_RST_CTL_PB_BAR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_RST_CTL_PB_BAR_RESET]

//>> GET_[INT_CQ_RST_CTL_PB_BAR_RESET]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_RST_CTL_PB_BAR_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.extractToRight<INT_CQ_RST_CTL_PB_BAR_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_RST_CTL_PB_BAR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_PB_BAR_RESET]

//>> GET_[INT_CQ_RST_CTL_PB_BAR_RESET]
static inline bool GET_INT_CQ_RST_CTL_PB_BAR_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.getBit<INT_CQ_RST_CTL_PB_BAR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_RST_CTL_PB_BAR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_PB_BAR_RESET]

//>> SET_[INT_CQ_RST_CTL_RESERVED_5_7]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_RESERVED_5_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_RESERVED_5_7,
           INT_CQ_RST_CTL_RESERVED_5_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_RST_CTL_RESERVED_5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_RESERVED_5_7]

//>> SET_[INT_CQ_RST_CTL_RESERVED_5_7]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_RST_CTL_RESERVED_5_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return o_data.insertFromRight<INT_CQ_RST_CTL_RESERVED_5_7,
           INT_CQ_RST_CTL_RESERVED_5_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_RST_CTL_RESERVED_5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_RST_CTL_RESERVED_5_7]

//>> GET_[INT_CQ_RST_CTL_RESERVED_5_7]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_RST_CTL_RESERVED_5_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_RST_CTL));
#endif
    return i_data.extractToRight<INT_CQ_RST_CTL_RESERVED_5_7,
           INT_CQ_RST_CTL_RESERVED_5_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_RST_CTL_RESERVED_5_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_RST_CTL_RESERVED_5_7]

//>> PREP_[MCD_BANK0_BOT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_BOT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_BOT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_BANK0_BOT]

//>> GET_[MCD_BANK0_BOT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_BOT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_BOT;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_BOT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_BANK0_BOT]

//>> PUT_[MCD_BANK0_BOT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_BOT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_BOT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_BANK0_BOT]


//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.setBit<MCD_BANK0_BOT_BANK0_MCD_BOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]

//>> CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_BOT_BANK0_MCD_BOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.clearBit<MCD_BANK0_BOT_BANK0_MCD_BOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_BANK0_MCD_BOT_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_BANK0_MCD_BOT_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]
static inline bool GET_MCD_BANK0_BOT_BANK0_MCD_BOT_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.getBit<MCD_BANK0_BOT_BANK0_MCD_BOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_VALID]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_CPG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_CPG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.setBit<MCD_BANK0_BOT_BANK0_MCD_BOT_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]

//>> CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_BOT_BANK0_MCD_BOT_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.clearBit<MCD_BANK0_BOT_BANK0_MCD_BOT_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_BANK0_MCD_BOT_CPG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_BANK0_MCD_BOT_CPG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]
static inline bool GET_MCD_BANK0_BOT_BANK0_MCD_BOT_CPG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.getBit<MCD_BANK0_BOT_BANK0_MCD_BOT_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_CPG]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.setBit<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]

//>> CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.clearBit<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]
static inline bool GET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.getBit<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_MBR_ID]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.setBit<MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]

//>> CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.clearBit<MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]
static inline bool GET_MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.getBit<MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_ALWAYS_RTY]

//>> SET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]

//>> SET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]

//>> SET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.setBit<MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]

//>> CLEAR_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.clearBit<MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]

//>> GET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]

//>> GET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]
static inline bool GET_MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.getBit<MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_MCD_BOT_SMF_ENABLE]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.setBit<MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]

//>> CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.clearBit<MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]
static inline bool GET_MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.getBit<MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_SMF_ENABLE]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE,
           MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE,
           MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE,
           MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_SIZE]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE,
           MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE]

//>> SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return o_data.insertFromRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE,
           MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE]

//>> GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_BOT));
#endif
    return i_data.extractToRight<MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE,
           MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_BOT_BANK0_MCD_BOT_GRP_BASE]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM1_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM1_LAST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM1_LAST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM1_LAST]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM1_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM1_LAST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM1_LAST;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM1_LAST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM1_LAST]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM1_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM1_LAST(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM1_LAST));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM1_LAST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM1_LAST]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM1_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM1_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM1_LAST));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM1_LAST_HTM1_LAST_ADDRESS]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_MODE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_MODE;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_MODE]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_W511975_CHICKENSW]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE16]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE23]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_MODE));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043,
           PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SPARE4043]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR_PB_CFG_SPARE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
