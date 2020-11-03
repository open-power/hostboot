/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00075.H $         */
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

#ifndef __PROC_REG00075_H_
#define __PROC_REG00075_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_CQ_TM_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_TM_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TM_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_CQ_TM_BAR]

//>> GET_[INT_CQ_TM_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_TM_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TM_BAR;
#endif
    return fapi2::getScom(i_target, INT_CQ_TM_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_CQ_TM_BAR]

//>> PUT_[INT_CQ_TM_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_TM_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return fapi2::putScom(i_target, INT_CQ_TM_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_CQ_TM_BAR]


//>> SET_[INT_CQ_TM_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_VALID]

//>> SET_[INT_CQ_TM_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_VALID]

//>> SET_[INT_CQ_TM_BAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.setBit<INT_CQ_TM_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_VALID]

//>> CLEAR_[INT_CQ_TM_BAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.clearBit<INT_CQ_TM_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_TM_BAR_VALID]

//>> GET_[INT_CQ_TM_BAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.extractToRight<INT_CQ_TM_BAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TM_BAR_VALID]

//>> GET_[INT_CQ_TM_BAR_VALID]
static inline bool GET_INT_CQ_TM_BAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.getBit<INT_CQ_TM_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_TM_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TM_BAR_VALID]

//>> SET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.setBit<INT_CQ_TM_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]

//>> CLEAR_[INT_CQ_TM_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.clearBit<INT_CQ_TM_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_CQ_TM_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.extractToRight<INT_CQ_TM_BAR_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]

//>> GET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]
static inline bool GET_INT_CQ_TM_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.getBit<INT_CQ_TM_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_CQ_TM_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TM_BAR_PAGE_SIZE_64K]

//>> SET_[INT_CQ_TM_BAR_ADDR_8_49]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_ADDR_8_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_ADDR_8_49,
           INT_CQ_TM_BAR_ADDR_8_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TM_BAR_ADDR_8_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_ADDR_8_49]

//>> SET_[INT_CQ_TM_BAR_ADDR_8_49]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TM_BAR_ADDR_8_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_TM_BAR_ADDR_8_49,
           INT_CQ_TM_BAR_ADDR_8_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TM_BAR_ADDR_8_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TM_BAR_ADDR_8_49]

//>> GET_[INT_CQ_TM_BAR_ADDR_8_49]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TM_BAR_ADDR_8_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TM_BAR));
#endif
    return i_data.extractToRight<INT_CQ_TM_BAR_ADDR_8_49,
           INT_CQ_TM_BAR_ADDR_8_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TM_BAR_ADDR_8_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TM_BAR_ADDR_8_49]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES,
           PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]

//>> PREP_[PB_PTLSCOM10_FP01_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_FP01_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP01_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_FP01_CFG]

//>> GET_[PB_PTLSCOM10_FP01_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_FP01_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP01_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_FP01_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG]

//>> PUT_[PB_PTLSCOM10_FP01_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_FP01_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_FP01_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_FP01_CFG]


//>> SET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME,
           PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME]

//>> SET_[PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME,
           PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME]

//>> GET_[PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME,
           PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_01_CMD_EXP_TIME]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE]

//>> GET_[PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_0_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_FMR_SPARE]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE]

//>> GET_[PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP01_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE,
           PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP01_CFG_1_PRS_SPARE]

//>> PREP_[PB_PTLSCOM10_MISC_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MISC_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MISC_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_MISC_CFG]

//>> GET_[PB_PTLSCOM10_MISC_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MISC_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MISC_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG]

//>> PUT_[PB_PTLSCOM10_MISC_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MISC_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MISC_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_MISC_CFG]


//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_ENABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> SET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]

//>> CLEAR_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]
static inline bool GET_PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_HW517132_DISABLE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_MISC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_MISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_MISC_SPARE,
           PB_PTLSCOM10_MISC_CFG_MISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_MISC_SPARE]

//>> SET_[PB_PTLSCOM10_MISC_CFG_MISC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MISC_CFG_MISC_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MISC_CFG_MISC_SPARE,
           PB_PTLSCOM10_MISC_CFG_MISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_MISC_CFG_MISC_SPARE]

//>> GET_[PB_PTLSCOM10_MISC_CFG_MISC_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MISC_CFG_MISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MISC_CFG_MISC_SPARE,
           PB_PTLSCOM10_MISC_CFG_MISC_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_MISC_CFG_MISC_SPARE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
