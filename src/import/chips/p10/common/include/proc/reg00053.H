/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00053.H $         */
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

#ifndef __PROC_REG00053_H_
#define __PROC_REG00053_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK]

//>> PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM]

//>> PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM]


//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ADDR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_R_NW]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BUSY]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_BYTE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_LINE_MODE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_DATAOP_PENDING]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1_PIB_MASTER_ID]

//>> PREP_[TP_TPCHIP_TPC_XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_XSTOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_XSTOP]

//>> GET_[TP_TPCHIP_TPC_XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_XSTOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_XSTOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP]

//>> PUT_[TP_TPCHIP_TPC_XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_XSTOP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_XSTOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_XSTOP]


//>> SET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_ANY_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]

//>> SET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_ANY_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_ANY_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]

//>> SET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_ANY_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_ANY_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]

//>> GET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_ANY_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]

//>> GET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_ANY_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_ANY_XSTOP]

//>> SET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]

//>> SET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]

//>> SET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]

//>> GET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]

//>> GET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_SYSTEM_XSTOP]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_ANY_SPATTN]

//>> SET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> SET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> SET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> GET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> GET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_PERV]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN05]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN06]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN07]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN08]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN09]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN10]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN11]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN12]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN13]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN14]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN15]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN16]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN17]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN18]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN19]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN20]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN21]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN22]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN23]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN24]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN25]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN26]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN27]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN28]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN29]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN30]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN31]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN32]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN33]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN34]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN35]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN36]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN37]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN38]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN39]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN40]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN41]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN42]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN43]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN44]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN45]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN46]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN47]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN48]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN49]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN50]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN51]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN52]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]

//>> SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]

//>> CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_XSTOP_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_XSTOP_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]

//>> GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]
static inline bool GET_TP_TPCHIP_TPC_XSTOP_XSTOP_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_XSTOP_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_XSTOP_XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_XSTOP_XSTOP_IN53]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG]

//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_SCOM_CMD_REGISTER_DMA_SCOM_CMD_REG]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
