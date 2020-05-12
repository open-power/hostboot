/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00049.H $         */
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

#ifndef __PROC_REG00049_H_
#define __PROC_REG00049_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
