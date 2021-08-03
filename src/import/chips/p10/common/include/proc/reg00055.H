/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00055.H $         */
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

#ifndef __PROC_REG00055_H_
#define __PROC_REG00055_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_CQ_IC_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_IC_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_IC_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_CQ_IC_BAR]

//>> GET_[INT_CQ_IC_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_IC_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_IC_BAR;
#endif
    return fapi2::getScom(i_target, INT_CQ_IC_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_CQ_IC_BAR]

//>> PUT_[INT_CQ_IC_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_IC_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return fapi2::putScom(i_target, INT_CQ_IC_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_CQ_IC_BAR]


//>> SET_[INT_CQ_IC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_VALID]

//>> SET_[INT_CQ_IC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_VALID]

//>> SET_[INT_CQ_IC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.setBit<INT_CQ_IC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_VALID]

//>> CLEAR_[INT_CQ_IC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.clearBit<INT_CQ_IC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_IC_BAR_VALID]

//>> GET_[INT_CQ_IC_BAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_IC_BAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_IC_BAR_VALID]

//>> GET_[INT_CQ_IC_BAR_VALID]
static inline bool GET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.getBit<INT_CQ_IC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_IC_BAR_VALID]

//>> SET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.setBit<INT_CQ_IC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]

//>> CLEAR_[INT_CQ_IC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.clearBit<INT_CQ_IC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_IC_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_IC_BAR_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]
static inline bool GET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.getBit<INT_CQ_IC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_IC_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_IC_BAR_ADDR_8_42]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_ADDR_8_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_ADDR_8_42,
           INT_CQ_IC_BAR_ADDR_8_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_IC_BAR_ADDR_8_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_ADDR_8_42]

//>> SET_[INT_CQ_IC_BAR_ADDR_8_42]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_ADDR_8_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_ADDR_8_42,
           INT_CQ_IC_BAR_ADDR_8_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_IC_BAR_ADDR_8_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_IC_BAR_ADDR_8_42]

//>> GET_[INT_CQ_IC_BAR_ADDR_8_42]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_IC_BAR_ADDR_8_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_IC_BAR_ADDR_8_42,
           INT_CQ_IC_BAR_ADDR_8_42_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_IC_BAR_ADDR_8_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_IC_BAR_ADDR_8_42]

//>> PREP_[MCD_BANK0_STR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_STR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_STR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_BANK0_STR]

//>> GET_[MCD_BANK0_STR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_STR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_STR;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_STR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_BANK0_STR]

//>> PUT_[MCD_BANK0_STR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_STR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_STR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_BANK0_STR]


//>> SET_[MCD_BANK0_STR_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_VALID]

//>> SET_[MCD_BANK0_STR_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_VALID]

//>> SET_[MCD_BANK0_STR_VALID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_VALID]

//>> CLEAR_[MCD_BANK0_STR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_STR_VALID]

//>> GET_[MCD_BANK0_STR_VALID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_VALID]

//>> GET_[MCD_BANK0_STR_VALID]
static inline bool GET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_VALID]

//>> SET_[MCD_BANK0_STR_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_CPG]

//>> SET_[MCD_BANK0_STR_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_CPG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_CPG]

//>> SET_[MCD_BANK0_STR_CPG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_CPG]

//>> CLEAR_[MCD_BANK0_STR_CPG]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_STR_CPG]

//>> GET_[MCD_BANK0_STR_CPG]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_CPG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_CPG]

//>> GET_[MCD_BANK0_STR_CPG]
static inline bool GET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_CPG]

//>> SET_[MCD_BANK0_STR_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_GRP_MBR_ID]

//>> SET_[MCD_BANK0_STR_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_MBR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_GRP_MBR_ID]

//>> SET_[MCD_BANK0_STR_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_GRP_MBR_ID]

//>> CLEAR_[MCD_BANK0_STR_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_STR_GRP_MBR_ID]

//>> GET_[MCD_BANK0_STR_GRP_MBR_ID]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_GRP_MBR_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_GRP_MBR_ID]

//>> GET_[MCD_BANK0_STR_GRP_MBR_ID]
static inline bool GET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_GRP_MBR_ID]

//>> SET_[MCD_BANK0_STR_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_ALWAYS_RTY]

//>> SET_[MCD_BANK0_STR_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_ALWAYS_RTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_ALWAYS_RTY]

//>> SET_[MCD_BANK0_STR_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_ALWAYS_RTY]

//>> CLEAR_[MCD_BANK0_STR_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_STR_ALWAYS_RTY]

//>> GET_[MCD_BANK0_STR_ALWAYS_RTY]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_ALWAYS_RTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_ALWAYS_RTY]

//>> GET_[MCD_BANK0_STR_ALWAYS_RTY]
static inline bool GET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_ALWAYS_RTY]

//>> SET_[MCD_BANK0_STR_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_SMF_ENABLE]

//>> SET_[MCD_BANK0_STR_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_SMF_ENABLE]

//>> SET_[MCD_BANK0_STR_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_SMF_ENABLE]

//>> CLEAR_[MCD_BANK0_STR_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_STR_SMF_ENABLE]

//>> GET_[MCD_BANK0_STR_SMF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_SMF_ENABLE]

//>> GET_[MCD_BANK0_STR_SMF_ENABLE]
static inline bool GET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_SMF_ENABLE]

//>> SET_[MCD_BANK0_STR_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_SIZE,
           MCD_BANK0_STR_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_STR_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_GRP_SIZE]

//>> SET_[MCD_BANK0_STR_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_SIZE,
           MCD_BANK0_STR_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_STR_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_GRP_SIZE]

//>> GET_[MCD_BANK0_STR_GRP_SIZE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_GRP_SIZE,
           MCD_BANK0_STR_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_STR_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_GRP_SIZE]

//>> SET_[MCD_BANK0_STR_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_BASE,
           MCD_BANK0_STR_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_STR_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_GRP_BASE]

//>> SET_[MCD_BANK0_STR_GRP_BASE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_BASE,
           MCD_BANK0_STR_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_STR_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_STR_GRP_BASE]

//>> GET_[MCD_BANK0_STR_GRP_BASE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_GRP_BASE,
           MCD_BANK0_STR_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_STR_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_STR_GRP_BASE]

//>> PREP_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG]

//>> GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG]

//>> PUT_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG]


//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7]

//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7]

//>> GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_VALID_BITS_FOR_ENTRIES_0_7]

//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07]

//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07]

//>> GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07]

//>> PREP_[NX_PBI_RNG_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_RNG_CFG]

//>> GET_[NX_PBI_RNG_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_CFG;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_RNG_CFG]

//>> PUT_[NX_PBI_RNG_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_RNG_CFG]


//>> SET_[NX_PBI_RNG_CFG_FAIL_REG]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_FAIL_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_FAIL_REG,
           NX_PBI_RNG_CFG_FAIL_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_FAIL_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_FAIL_REG]

//>> SET_[NX_PBI_RNG_CFG_FAIL_REG]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_FAIL_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_FAIL_REG,
           NX_PBI_RNG_CFG_FAIL_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_FAIL_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_FAIL_REG]

//>> GET_[NX_PBI_RNG_CFG_FAIL_REG]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_FAIL_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_FAIL_REG,
           NX_PBI_RNG_CFG_FAIL_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_FAIL_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_FAIL_REG]

//>> SET_[NX_PBI_RNG_CFG_RNG0_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG0_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG0_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG0_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_FAIL]

//>> CLEAR_[NX_PBI_RNG_CFG_RNG0_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG0_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RNG0_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG0_FAIL]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG0_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG0_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG0_FAIL]
static inline bool GET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG0_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG0_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG1_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG1_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG1_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG1_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_FAIL]

//>> CLEAR_[NX_PBI_RNG_CFG_RNG1_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG1_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RNG1_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG1_FAIL]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG1_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG1_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG1_FAIL]
static inline bool GET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG1_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG1_FAIL]

//>> SET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_INTERRUPT_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]

//>> SET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_INTERRUPT_SENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_INTERRUPT_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]

//>> SET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_INTERRUPT_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]

//>> CLEAR_[NX_PBI_RNG_CFG_INTERRUPT_SENT]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_INTERRUPT_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_INTERRUPT_SENT]

//>> GET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_INTERRUPT_SENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]

//>> GET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]
static inline bool GET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_INTERRUPT_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_INTERRUPT_SENT]

//>> SET_[NX_PBI_RNG_CFG_BIST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_BIST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_BIST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_BIST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_BIST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_BIST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_BIST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_BIST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_BIST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_BIST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_BIST_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_BIST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_BIST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_BIST_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_COMPLETE]

//>> SET_[NX_PBI_RNG_CFG_BIST_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_COMPLETE]

//>> SET_[NX_PBI_RNG_CFG_BIST_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_BIST_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_COMPLETE]

//>> CLEAR_[NX_PBI_RNG_CFG_BIST_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_BIST_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_BIST_COMPLETE]

//>> GET_[NX_PBI_RNG_CFG_BIST_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_BIST_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_BIST_COMPLETE]

//>> GET_[NX_PBI_RNG_CFG_BIST_COMPLETE]
static inline bool GET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_BIST_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_BIST_COMPLETE]

//>> SET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG0_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]

//>> CLEAR_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG0_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG0_BIST_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]
static inline bool GET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG0_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG0_BIST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG1_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]

//>> CLEAR_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG1_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG1_BIST_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]

//>> GET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]
static inline bool GET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG1_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG1_BIST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH,
           NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH]

//>> SET_[NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH,
           NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH]

//>> GET_[NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH,
           NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH]

//>> SET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]

//>> SET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]

//>> SET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]

//>> CLEAR_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]

//>> GET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]

//>> GET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]
static inline bool GET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR]

//>> SET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]

//>> SET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]

//>> SET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]

//>> CLEAR_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]

//>> GET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]

//>> GET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]
static inline bool GET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR]

//>> SET_[NX_PBI_RNG_CFG_ST2_RESET_PERIOD]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ST2_RESET_PERIOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ST2_RESET_PERIOD,
           NX_PBI_RNG_CFG_ST2_RESET_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_ST2_RESET_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ST2_RESET_PERIOD]

//>> SET_[NX_PBI_RNG_CFG_ST2_RESET_PERIOD]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ST2_RESET_PERIOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ST2_RESET_PERIOD,
           NX_PBI_RNG_CFG_ST2_RESET_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_ST2_RESET_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ST2_RESET_PERIOD]

//>> GET_[NX_PBI_RNG_CFG_ST2_RESET_PERIOD]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_ST2_RESET_PERIOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_ST2_RESET_PERIOD,
           NX_PBI_RNG_CFG_ST2_RESET_PERIOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_ST2_RESET_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_ST2_RESET_PERIOD]

//>> SET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_SAMPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_SAMPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_SAMPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_SAMPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_SAMPTEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_SAMPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_SAMPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_REPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_REPTEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_REPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_REPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_REPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_REPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_REPTEST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_REPTEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_REPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_REPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_ADAPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_ADAPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_ADAPTEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_ADAPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_ADAPTEST_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]

//>> CLEAR_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]

//>> GET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]

//>> GET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]
static inline bool GET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL]

//>> SET_[NX_PBI_RNG_CFG_PACE_RATE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_PACE_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_PACE_RATE,
           NX_PBI_RNG_CFG_PACE_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_PACE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_PACE_RATE]

//>> SET_[NX_PBI_RNG_CFG_PACE_RATE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_PACE_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_PACE_RATE,
           NX_PBI_RNG_CFG_PACE_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_PACE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_PACE_RATE]

//>> GET_[NX_PBI_RNG_CFG_PACE_RATE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_PACE_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_PACE_RATE,
           NX_PBI_RNG_CFG_PACE_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_PACE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_PACE_RATE]

//>> SET_[NX_PBI_RNG_CFG_RNG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_RNG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG_ENABLE]

//>> SET_[NX_PBI_RNG_CFG_RNG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_CFG_RNG_ENABLE]

//>> CLEAR_[NX_PBI_RNG_CFG_RNG_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_CFG_RNG_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_RNG_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG_ENABLE]

//>> GET_[NX_PBI_RNG_CFG_RNG_ENABLE]
static inline bool GET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_CFG_RNG_ENABLE]

//>> PREP_[NX_PBI_RNG_ST2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_ST2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_RNG_ST2]

//>> GET_[NX_PBI_RNG_ST2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_ST2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST2;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_ST2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_RNG_ST2]

//>> PUT_[NX_PBI_RNG_ST2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_ST2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_ST2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_RNG_ST2]


//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0]

//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0]

//>> GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0]

//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1]

//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1]

//>> GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1]

//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0]

//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0]

//>> GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0]

//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1]

//>> SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1]

//>> GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1]

//>> SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0]

//>> SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0]

//>> GET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0]

//>> SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1]

//>> SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1]

//>> GET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
