/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00068.H $         */
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

#ifndef __PROC_REG00068_H_
#define __PROC_REG00068_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_FMIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN]

//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI]

//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_ANY_ERROR]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SYSTEM_CHECKSTOP]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SPECIAL_ATTENTION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RECOVERABLE_ERROR]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PARITY_CHECK]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PROTECTION_CHECK]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_8]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_9]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_IDLE_INDICATION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ABORT]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC,
           TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC,
           TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC,
           TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_RCS_ERROR_STATUS_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_VDD_NEST_OBSERVE]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE,
           TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE,
           TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE,
           TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_PIB_ERROR_CODE]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_0_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_1_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_2_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_3_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_4_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_5_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_6_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_TP_TPFSI_PLL_LOCK_7_DC]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_INTERRUPT_ENABLED]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI, TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_STATUS_RESERVED_31]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
