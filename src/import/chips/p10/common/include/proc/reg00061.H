/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00061.H $         */
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

#ifndef __PROC_REG00061_H_
#define __PROC_REG00061_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIRACT1]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRACT1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRACT1]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIRACT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIRACT1]


//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1,
           TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1,
           TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1,
           TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]

//>> PREP_[TP_TPBR_PBA_PBAO_BCUE_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCUE_STAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_STAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCUE_STAT]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCUE_STAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_STAT;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCUE_STAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT]

//>> PUT_[TP_TPBR_PBA_PBAO_BCUE_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCUE_STAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCUE_STAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCUE_STAT]


//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]
static inline bool GET_TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RUNNING]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]
static inline bool GET_TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WAITING]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP,
           TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP,
           TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP,
           TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_WRCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP,
           TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP,
           TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP,
           TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_RDCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG,
           TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG,
           TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG,
           TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DEBUG]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]
static inline bool GET_TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_STOPPED]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]
static inline bool GET_TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_ERROR]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_STAT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_STAT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCUE_STAT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCUE_STAT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCUE_STAT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_STAT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_STAT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]
static inline bool GET_TP_TPBR_PBA_PBAO_BCUE_STAT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCUE_STAT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_STAT_DONE]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAOCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAOCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAOCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAOCFG]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAOCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAOCFG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAOCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAOCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAOCFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAOCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAOCFG]


//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_ADRERROR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIABUSPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIBEPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_HANG_ON_DERROR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_WRITE_MATCH_REARB]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_GEN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DIS_OCIDATAPAR_CHECK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_USE_TOPOLOGY_ID_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_HTM_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11,
           TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11,
           TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11,
           TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_9_11]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_RD]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_15]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_LN_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_NN_RN_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_CHSW_DISABLE_GROUP_WR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]

//>> SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]

//>> GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAOCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAOCFG_RESERVED_19]

//>> PREP_[PB_PTLSCOM10_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PR0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PR0123_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_PR0123_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PR0123_ERR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PR0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR]

//>> PUT_[PB_PTLSCOM10_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PR0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_PR0123_ERR]


//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]
static inline bool GET_PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PR0123_ERR_3_LINK_DOWN]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
