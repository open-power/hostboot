/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00041.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __PROC_REG00041_H_
#define __PROC_REG00041_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_CQ_NVC_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_NVC_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_NVC_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_CQ_NVC_BAR]

//>> GET_[INT_CQ_NVC_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_NVC_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_NVC_BAR;
#endif
    return fapi2::getScom(i_target, INT_CQ_NVC_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_CQ_NVC_BAR]

//>> PUT_[INT_CQ_NVC_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_NVC_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return fapi2::putScom(i_target, INT_CQ_NVC_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_CQ_NVC_BAR]


//>> SET_[INT_CQ_NVC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_VALID]

//>> SET_[INT_CQ_NVC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_VALID]

//>> SET_[INT_CQ_NVC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.setBit<INT_CQ_NVC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_VALID]

//>> CLEAR_[INT_CQ_NVC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.clearBit<INT_CQ_NVC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_NVC_BAR_VALID]

//>> GET_[INT_CQ_NVC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVC_BAR_VALID]

//>> GET_[INT_CQ_NVC_BAR_VALID]
static inline bool GET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return i_data.getBit<INT_CQ_NVC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVC_BAR_VALID]

//>> SET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.setBit<INT_CQ_NVC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]

//>> CLEAR_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.clearBit<INT_CQ_NVC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]
static inline bool GET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return i_data.getBit<INT_CQ_NVC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVC_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_NVC_BAR_ADDR_8_39]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_ADDR_8_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_ADDR_8_39,
           INT_CQ_NVC_BAR_ADDR_8_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVC_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_ADDR_8_39]

//>> SET_[INT_CQ_NVC_BAR_ADDR_8_39]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_ADDR_8_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_ADDR_8_39,
           INT_CQ_NVC_BAR_ADDR_8_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVC_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_ADDR_8_39]

//>> GET_[INT_CQ_NVC_BAR_ADDR_8_39]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_ADDR_8_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_ADDR_8_39,
           INT_CQ_NVC_BAR_ADDR_8_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVC_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVC_BAR_ADDR_8_39]

//>> SET_[INT_CQ_NVC_BAR_SET_DIV_SEL_0_2]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_SET_DIV_SEL_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVC_BAR_SET_DIV_SEL_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVC_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_SET_DIV_SEL_0_2]

//>> SET_[INT_CQ_NVC_BAR_SET_DIV_SEL_0_2]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_SET_DIV_SEL_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVC_BAR_SET_DIV_SEL_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVC_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_SET_DIV_SEL_0_2]

//>> GET_[INT_CQ_NVC_BAR_SET_DIV_SEL_0_2]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_SET_DIV_SEL_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVC_BAR_SET_DIV_SEL_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVC_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVC_BAR_SET_DIV_SEL_0_2]

//>> SET_[INT_CQ_NVC_BAR_RANGE_0_4]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_RANGE_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_RANGE_0_4,
           INT_CQ_NVC_BAR_RANGE_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_NVC_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_RANGE_0_4]

//>> SET_[INT_CQ_NVC_BAR_RANGE_0_4]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_RANGE_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_RANGE_0_4,
           INT_CQ_NVC_BAR_RANGE_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_NVC_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_NVC_BAR_RANGE_0_4]

//>> GET_[INT_CQ_NVC_BAR_RANGE_0_4]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_RANGE_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_RANGE_0_4,
           INT_CQ_NVC_BAR_RANGE_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_NVC_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_NVC_BAR_RANGE_0_4]

//>> PREP_[MCD_BANK0_CHA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_CHA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_CHA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_BANK0_CHA]

//>> GET_[MCD_BANK0_CHA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_CHA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_CHA;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_CHA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_BANK0_CHA]

//>> PUT_[MCD_BANK0_CHA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_CHA(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_CHA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_BANK0_CHA]


//>> SET_[MCD_BANK0_CHA_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_VALID]

//>> SET_[MCD_BANK0_CHA_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_VALID]

//>> SET_[MCD_BANK0_CHA_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.setBit<MCD_BANK0_CHA_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_VALID]

//>> CLEAR_[MCD_BANK0_CHA_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_CHA_VALID]

//>> GET_[MCD_BANK0_CHA_VALID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_VALID]

//>> GET_[MCD_BANK0_CHA_VALID]
static inline bool GET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.getBit<MCD_BANK0_CHA_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_VALID]

//>> SET_[MCD_BANK0_CHA_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_CPG]

//>> SET_[MCD_BANK0_CHA_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_CPG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_CPG]

//>> SET_[MCD_BANK0_CHA_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.setBit<MCD_BANK0_CHA_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_CPG]

//>> CLEAR_[MCD_BANK0_CHA_CPG]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_CHA_CPG]

//>> GET_[MCD_BANK0_CHA_CPG]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_CPG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_CPG]

//>> GET_[MCD_BANK0_CHA_CPG]
static inline bool GET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.getBit<MCD_BANK0_CHA_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_CPG]

//>> SET_[MCD_BANK0_CHA_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_GRP_MBR_ID]

//>> SET_[MCD_BANK0_CHA_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_MBR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_GRP_MBR_ID]

//>> SET_[MCD_BANK0_CHA_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.setBit<MCD_BANK0_CHA_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_GRP_MBR_ID]

//>> CLEAR_[MCD_BANK0_CHA_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_CHA_GRP_MBR_ID]

//>> GET_[MCD_BANK0_CHA_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_GRP_MBR_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_GRP_MBR_ID]

//>> GET_[MCD_BANK0_CHA_GRP_MBR_ID]
static inline bool GET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.getBit<MCD_BANK0_CHA_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_GRP_MBR_ID]

//>> SET_[MCD_BANK0_CHA_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_ALWAYS_RTY]

//>> SET_[MCD_BANK0_CHA_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_ALWAYS_RTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_ALWAYS_RTY]

//>> SET_[MCD_BANK0_CHA_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.setBit<MCD_BANK0_CHA_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_ALWAYS_RTY]

//>> CLEAR_[MCD_BANK0_CHA_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_CHA_ALWAYS_RTY]

//>> GET_[MCD_BANK0_CHA_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_ALWAYS_RTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_ALWAYS_RTY]

//>> GET_[MCD_BANK0_CHA_ALWAYS_RTY]
static inline bool GET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.getBit<MCD_BANK0_CHA_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_ALWAYS_RTY]

//>> SET_[MCD_BANK0_CHA_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_SMF_ENABLE]

//>> SET_[MCD_BANK0_CHA_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_SMF_ENABLE]

//>> SET_[MCD_BANK0_CHA_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.setBit<MCD_BANK0_CHA_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_SMF_ENABLE]

//>> CLEAR_[MCD_BANK0_CHA_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_CHA_SMF_ENABLE]

//>> GET_[MCD_BANK0_CHA_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_SMF_ENABLE]

//>> GET_[MCD_BANK0_CHA_SMF_ENABLE]
static inline bool GET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.getBit<MCD_BANK0_CHA_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_SMF_ENABLE]

//>> SET_[MCD_BANK0_CHA_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_SIZE,
           MCD_BANK0_CHA_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_GRP_SIZE]

//>> SET_[MCD_BANK0_CHA_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_SIZE,
           MCD_BANK0_CHA_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_GRP_SIZE]

//>> GET_[MCD_BANK0_CHA_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_GRP_SIZE,
           MCD_BANK0_CHA_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_GRP_SIZE]

//>> SET_[MCD_BANK0_CHA_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_BASE,
           MCD_BANK0_CHA_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_GRP_BASE]

//>> SET_[MCD_BANK0_CHA_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_BASE,
           MCD_BANK0_CHA_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_CHA_GRP_BASE]

//>> GET_[MCD_BANK0_CHA_GRP_BASE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_GRP_BASE,
           MCD_BANK0_CHA_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_CHA_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_CHA_GRP_BASE]

//>> PREP_[MCD_BANK0_TOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_TOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_TOP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_BANK0_TOP]

//>> GET_[MCD_BANK0_TOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_TOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_TOP;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_TOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_BANK0_TOP]

//>> PUT_[MCD_BANK0_TOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_TOP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_TOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_BANK0_TOP]


//>> SET_[MCD_BANK0_TOP_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_VALID]

//>> SET_[MCD_BANK0_TOP_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_VALID]

//>> SET_[MCD_BANK0_TOP_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.setBit<MCD_BANK0_TOP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_VALID]

//>> CLEAR_[MCD_BANK0_TOP_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_TOP_VALID]

//>> GET_[MCD_BANK0_TOP_VALID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_VALID]

//>> GET_[MCD_BANK0_TOP_VALID]
static inline bool GET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.getBit<MCD_BANK0_TOP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_VALID]

//>> SET_[MCD_BANK0_TOP_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_CPG]

//>> SET_[MCD_BANK0_TOP_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_CPG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_CPG]

//>> SET_[MCD_BANK0_TOP_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.setBit<MCD_BANK0_TOP_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_CPG]

//>> CLEAR_[MCD_BANK0_TOP_CPG]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_TOP_CPG]

//>> GET_[MCD_BANK0_TOP_CPG]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_CPG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_CPG]

//>> GET_[MCD_BANK0_TOP_CPG]
static inline bool GET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.getBit<MCD_BANK0_TOP_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_CPG]

//>> SET_[MCD_BANK0_TOP_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_GRP_MBR_ID]

//>> SET_[MCD_BANK0_TOP_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_MBR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_GRP_MBR_ID]

//>> SET_[MCD_BANK0_TOP_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.setBit<MCD_BANK0_TOP_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_GRP_MBR_ID]

//>> CLEAR_[MCD_BANK0_TOP_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_TOP_GRP_MBR_ID]

//>> GET_[MCD_BANK0_TOP_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_GRP_MBR_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_GRP_MBR_ID]

//>> GET_[MCD_BANK0_TOP_GRP_MBR_ID]
static inline bool GET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.getBit<MCD_BANK0_TOP_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_GRP_MBR_ID]

//>> SET_[MCD_BANK0_TOP_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_ALWAYS_RTY]

//>> SET_[MCD_BANK0_TOP_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_ALWAYS_RTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_ALWAYS_RTY]

//>> SET_[MCD_BANK0_TOP_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.setBit<MCD_BANK0_TOP_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_ALWAYS_RTY]

//>> CLEAR_[MCD_BANK0_TOP_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_TOP_ALWAYS_RTY]

//>> GET_[MCD_BANK0_TOP_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_ALWAYS_RTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_ALWAYS_RTY]

//>> GET_[MCD_BANK0_TOP_ALWAYS_RTY]
static inline bool GET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.getBit<MCD_BANK0_TOP_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_ALWAYS_RTY]

//>> SET_[MCD_BANK0_TOP_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_SMF_ENABLE]

//>> SET_[MCD_BANK0_TOP_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_SMF_ENABLE]

//>> SET_[MCD_BANK0_TOP_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.setBit<MCD_BANK0_TOP_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_SMF_ENABLE]

//>> CLEAR_[MCD_BANK0_TOP_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_TOP_SMF_ENABLE]

//>> GET_[MCD_BANK0_TOP_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_SMF_ENABLE]

//>> GET_[MCD_BANK0_TOP_SMF_ENABLE]
static inline bool GET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.getBit<MCD_BANK0_TOP_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_SMF_ENABLE]

//>> SET_[MCD_BANK0_TOP_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_SIZE,
           MCD_BANK0_TOP_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_GRP_SIZE]

//>> SET_[MCD_BANK0_TOP_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_SIZE,
           MCD_BANK0_TOP_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_GRP_SIZE]

//>> GET_[MCD_BANK0_TOP_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_GRP_SIZE,
           MCD_BANK0_TOP_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_GRP_SIZE]

//>> SET_[MCD_BANK0_TOP_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_BASE,
           MCD_BANK0_TOP_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_GRP_BASE]

//>> SET_[MCD_BANK0_TOP_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_BASE,
           MCD_BANK0_TOP_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_TOP_GRP_BASE]

//>> GET_[MCD_BANK0_TOP_GRP_BASE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_GRP_BASE,
           MCD_BANK0_TOP_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_TOP_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_TOP_GRP_BASE]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_CFG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_CFG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_CFG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_CFG3]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_CFG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_CFG3;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_CFG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_CFG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_CFG3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_CFG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_CFG3]


//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_CHIP_TSNOOP_DELAY_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2]

//>> GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_CFG3));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_SPARE2]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
