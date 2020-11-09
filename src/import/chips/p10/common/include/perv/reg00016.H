/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00016.H $         */
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

#ifndef __PERV_REG00016_H_
#define __PERV_REG00016_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[DPLL_CNTL_MISC_REGS_PFET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DPLL_CNTL_MISC_REGS_PFET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DPLL_CNTL_MISC_REGS_PFET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DPLL_CNTL_MISC_REGS_PFET]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DPLL_CNTL_MISC_REGS_PFET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DPLL_CNTL_MISC_REGS_PFET;
#endif
    return fapi2::getScom(i_target, DPLL_CNTL_MISC_REGS_PFET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET]

//>> PUT_[DPLL_CNTL_MISC_REGS_PFET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DPLL_CNTL_MISC_REGS_PFET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return fapi2::putScom(i_target, DPLL_CNTL_MISC_REGS_PFET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DPLL_CNTL_MISC_REGS_PFET]


//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.insertFromRight<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& SET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.setBit<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> CLEAR_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return o_data.clearBit<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline fapi2::buffer<uint64_t>& GET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.extractToRight<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]
static inline bool GET_DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DPLL_CNTL_MISC_REGS_PFET));
#endif
    return i_data.getBit<DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC]

//>> PREP_[EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_LOCAL_ACTION0]

//>> GET_[EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::getScom(i_target, EPS_FIR_LOCAL_ACTION0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0]

//>> PUT_[EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return fapi2::putScom(i_target, EPS_FIR_LOCAL_ACTION0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_LOCAL_ACTION0]


//>> SET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_00]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_00]

//>> GET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_00]

//>> GET_[EPS_FIR_LOCAL_ACTION0_00]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_01]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_01]

//>> GET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_01]

//>> GET_[EPS_FIR_LOCAL_ACTION0_01]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_02]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_02]

//>> GET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_02]

//>> GET_[EPS_FIR_LOCAL_ACTION0_02]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_03]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_03]

//>> GET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_03]

//>> GET_[EPS_FIR_LOCAL_ACTION0_03]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_04]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_04]

//>> GET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_04]

//>> GET_[EPS_FIR_LOCAL_ACTION0_04]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_05]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_05]

//>> GET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_05]

//>> GET_[EPS_FIR_LOCAL_ACTION0_05]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_06]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_06]

//>> GET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_06]

//>> GET_[EPS_FIR_LOCAL_ACTION0_06]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_07]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_07]

//>> GET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_07]

//>> GET_[EPS_FIR_LOCAL_ACTION0_07]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_08]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_08]

//>> GET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_08]

//>> GET_[EPS_FIR_LOCAL_ACTION0_08]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_09]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_09]

//>> GET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_09]

//>> GET_[EPS_FIR_LOCAL_ACTION0_09]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_10]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_10]

//>> GET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_10]

//>> GET_[EPS_FIR_LOCAL_ACTION0_10]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_11]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_11]

//>> GET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_11]

//>> GET_[EPS_FIR_LOCAL_ACTION0_11]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_12]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_12]

//>> GET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_12]

//>> GET_[EPS_FIR_LOCAL_ACTION0_12]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_13]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_13]

//>> GET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_13]

//>> GET_[EPS_FIR_LOCAL_ACTION0_13]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_14]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_14]

//>> GET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_14]

//>> GET_[EPS_FIR_LOCAL_ACTION0_14]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_15]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_15]

//>> GET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_15]

//>> GET_[EPS_FIR_LOCAL_ACTION0_15]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_16]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_16]

//>> GET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_16]

//>> GET_[EPS_FIR_LOCAL_ACTION0_16]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_17]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_17]

//>> GET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_17]

//>> GET_[EPS_FIR_LOCAL_ACTION0_17]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_18]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_18]

//>> GET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_18]

//>> GET_[EPS_FIR_LOCAL_ACTION0_18]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_19]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_19]

//>> GET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_19]

//>> GET_[EPS_FIR_LOCAL_ACTION0_19]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_20]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_20]

//>> GET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_20]

//>> GET_[EPS_FIR_LOCAL_ACTION0_20]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_21]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_21]

//>> GET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_21]

//>> GET_[EPS_FIR_LOCAL_ACTION0_21]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_22]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_22]

//>> GET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_22]

//>> GET_[EPS_FIR_LOCAL_ACTION0_22]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_23]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_23]

//>> GET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_23]

//>> GET_[EPS_FIR_LOCAL_ACTION0_23]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_24]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_24]

//>> GET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_24]

//>> GET_[EPS_FIR_LOCAL_ACTION0_24]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_25]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_25]

//>> GET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_25]

//>> GET_[EPS_FIR_LOCAL_ACTION0_25]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_26]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_26]

//>> GET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_26]

//>> GET_[EPS_FIR_LOCAL_ACTION0_26]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_27]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_27]

//>> GET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_27]

//>> GET_[EPS_FIR_LOCAL_ACTION0_27]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_28]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_28]

//>> GET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_28]

//>> GET_[EPS_FIR_LOCAL_ACTION0_28]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_29]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_29]

//>> GET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_29]

//>> GET_[EPS_FIR_LOCAL_ACTION0_29]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_30]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_30]

//>> GET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_30]

//>> GET_[EPS_FIR_LOCAL_ACTION0_30]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_31]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_31]

//>> GET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_31]

//>> GET_[EPS_FIR_LOCAL_ACTION0_31]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_32]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_32]

//>> GET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_32]

//>> GET_[EPS_FIR_LOCAL_ACTION0_32]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_33]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_33]

//>> GET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_33]

//>> GET_[EPS_FIR_LOCAL_ACTION0_33]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_34]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_34]

//>> GET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_34]

//>> GET_[EPS_FIR_LOCAL_ACTION0_34]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_35]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_35]

//>> GET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_35]

//>> GET_[EPS_FIR_LOCAL_ACTION0_35]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_36]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_36]

//>> GET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_36]

//>> GET_[EPS_FIR_LOCAL_ACTION0_36]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_37]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_37]

//>> GET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_37]

//>> GET_[EPS_FIR_LOCAL_ACTION0_37]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_38]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_38]

//>> GET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_38]

//>> GET_[EPS_FIR_LOCAL_ACTION0_38]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_39]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_39]

//>> GET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_39]

//>> GET_[EPS_FIR_LOCAL_ACTION0_39]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_40]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_40]

//>> GET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_40]

//>> GET_[EPS_FIR_LOCAL_ACTION0_40]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_41]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_41]

//>> GET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_41]

//>> GET_[EPS_FIR_LOCAL_ACTION0_41]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_42]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_42]

//>> GET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_42]

//>> GET_[EPS_FIR_LOCAL_ACTION0_42]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_43]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_43]

//>> GET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_43]

//>> GET_[EPS_FIR_LOCAL_ACTION0_43]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_44]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_44]

//>> GET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_44]

//>> GET_[EPS_FIR_LOCAL_ACTION0_44]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_45]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_45]

//>> GET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_45]

//>> GET_[EPS_FIR_LOCAL_ACTION0_45]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_46]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_46]

//>> GET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_46]

//>> GET_[EPS_FIR_LOCAL_ACTION0_46]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_47]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_47]

//>> GET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_47]

//>> GET_[EPS_FIR_LOCAL_ACTION0_47]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_48]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_48]

//>> GET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_48]

//>> GET_[EPS_FIR_LOCAL_ACTION0_48]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_49]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_49]

//>> GET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_49]

//>> GET_[EPS_FIR_LOCAL_ACTION0_49]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_50]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_50]

//>> GET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_50]

//>> GET_[EPS_FIR_LOCAL_ACTION0_50]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_51]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_51]

//>> GET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_51]

//>> GET_[EPS_FIR_LOCAL_ACTION0_51]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_52]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_52]

//>> GET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_52]

//>> GET_[EPS_FIR_LOCAL_ACTION0_52]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_53]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_53]

//>> GET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_53]

//>> GET_[EPS_FIR_LOCAL_ACTION0_53]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_54]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_54]

//>> GET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_54]

//>> GET_[EPS_FIR_LOCAL_ACTION0_54]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_55]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_55]

//>> GET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_55]

//>> GET_[EPS_FIR_LOCAL_ACTION0_55]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_56]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_56]

//>> GET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_56]

//>> GET_[EPS_FIR_LOCAL_ACTION0_56]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_57]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_57]

//>> GET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_57]

//>> GET_[EPS_FIR_LOCAL_ACTION0_57]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_58]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_58]

//>> GET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_58]

//>> GET_[EPS_FIR_LOCAL_ACTION0_58]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_59]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_59]

//>> GET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_59]

//>> GET_[EPS_FIR_LOCAL_ACTION0_59]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_60]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_60]

//>> GET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_60]

//>> GET_[EPS_FIR_LOCAL_ACTION0_60]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_61]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_61]

//>> GET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_61]

//>> GET_[EPS_FIR_LOCAL_ACTION0_61]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_62]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_62]

//>> GET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_62]

//>> GET_[EPS_FIR_LOCAL_ACTION0_62]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_63]

//>> SET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_63]

//>> SET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_63]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_63]

//>> GET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_63]

//>> GET_[EPS_FIR_LOCAL_ACTION0_63]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_63]

//>> PREP_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ERROR_REG]

//>> GET_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_REG;
#endif
    return fapi2::getScom(i_target, ERROR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ERROR_REG]

//>> PUT_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return fapi2::putScom(i_target, ERROR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ERROR_REG]


//>> SET_[ERROR_REG_TIMEOUT_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_TIMEOUT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_ACTIVE]

//>> SET_[ERROR_REG_TIMEOUT_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_TIMEOUT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_ACTIVE]

//>> SET_[ERROR_REG_TIMEOUT_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_TIMEOUT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_TIMEOUT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_ACTIVE]

//>> CLEAR_[ERROR_REG_TIMEOUT_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_TIMEOUT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_TIMEOUT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_TIMEOUT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_TIMEOUT_ACTIVE]

//>> GET_[ERROR_REG_TIMEOUT_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_TIMEOUT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_TIMEOUT_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_TIMEOUT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_ACTIVE]

//>> GET_[ERROR_REG_TIMEOUT_ACTIVE]
static inline bool GET_ERROR_REG_TIMEOUT_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_TIMEOUT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_TIMEOUT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_ACTIVE]

//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> CLEAR_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CE_ERROR]

//>> GET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CE_ERROR]

//>> GET_[ERROR_REG_CE_ERROR]
static inline bool GET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERR]

//>> SET_[ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERR]

//>> SET_[ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERR]

//>> CLEAR_[ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PARITY_ERR]

//>> GET_[ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERR]

//>> GET_[ERROR_REG_PARITY_ERR]
static inline bool GET_ERROR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERR]

//>> SET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ERRORS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ERRORS]

//>> SET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ERRORS]

//>> GET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_ERRORS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ERRORS]

//>> SET_[ERROR_REG_BEAT_NUM_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_BEAT_NUM_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_BEAT_NUM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_BEAT_NUM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_BEAT_NUM_ERR]

//>> SET_[ERROR_REG_BEAT_NUM_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_BEAT_NUM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_BEAT_NUM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_BEAT_NUM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_BEAT_NUM_ERR]

//>> SET_[ERROR_REG_BEAT_NUM_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_BEAT_NUM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_BEAT_NUM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_BEAT_NUM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_BEAT_NUM_ERR]

//>> CLEAR_[ERROR_REG_BEAT_NUM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_BEAT_NUM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_BEAT_NUM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_BEAT_NUM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_BEAT_NUM_ERR]

//>> GET_[ERROR_REG_BEAT_NUM_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_BEAT_NUM_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_BEAT_NUM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_BEAT_NUM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_BEAT_NUM_ERR]

//>> GET_[ERROR_REG_BEAT_NUM_ERR]
static inline bool GET_ERROR_REG_BEAT_NUM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_BEAT_NUM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_BEAT_NUM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_BEAT_NUM_ERR]

//>> SET_[ERROR_REG_BEAT_REC_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_BEAT_REC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_BEAT_REC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_BEAT_REC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_BEAT_REC_ERR]

//>> SET_[ERROR_REG_BEAT_REC_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_BEAT_REC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_BEAT_REC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_BEAT_REC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_BEAT_REC_ERR]

//>> SET_[ERROR_REG_BEAT_REC_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_BEAT_REC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_BEAT_REC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_BEAT_REC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_BEAT_REC_ERR]

//>> CLEAR_[ERROR_REG_BEAT_REC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_BEAT_REC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_BEAT_REC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_BEAT_REC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_BEAT_REC_ERR]

//>> GET_[ERROR_REG_BEAT_REC_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_BEAT_REC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_BEAT_REC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_BEAT_REC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_BEAT_REC_ERR]

//>> GET_[ERROR_REG_BEAT_REC_ERR]
static inline bool GET_ERROR_REG_BEAT_REC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_BEAT_REC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_BEAT_REC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_BEAT_REC_ERR]

//>> SET_[ERROR_REG_RECEIVED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_RECEIVED_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_RECEIVED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_RECEIVED_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_RECEIVED_ERROR]

//>> SET_[ERROR_REG_RECEIVED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_RECEIVED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_RECEIVED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_RECEIVED_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_RECEIVED_ERROR]

//>> SET_[ERROR_REG_RECEIVED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_RECEIVED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_RECEIVED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_RECEIVED_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_RECEIVED_ERROR]

//>> CLEAR_[ERROR_REG_RECEIVED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_RECEIVED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_RECEIVED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_RECEIVED_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_RECEIVED_ERROR]

//>> GET_[ERROR_REG_RECEIVED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_RECEIVED_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_RECEIVED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_RECEIVED_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_RECEIVED_ERROR]

//>> GET_[ERROR_REG_RECEIVED_ERROR]
static inline bool GET_ERROR_REG_RECEIVED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_RECEIVED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_RECEIVED_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_RECEIVED_ERROR]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_RX_PCB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_RX_PCB_DATA_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_RX_PCB_DATA_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_RX_PCB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_RX_PCB_DATA_P_ERR]

//>> SET_[ERROR_REG_RX_PCB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_RX_PCB_DATA_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_RX_PCB_DATA_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_RX_PCB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_RX_PCB_DATA_P_ERR]

//>> SET_[ERROR_REG_RX_PCB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_RX_PCB_DATA_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_RX_PCB_DATA_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_RX_PCB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_RX_PCB_DATA_P_ERR]

//>> CLEAR_[ERROR_REG_RX_PCB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_RX_PCB_DATA_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_RX_PCB_DATA_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_RX_PCB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_RX_PCB_DATA_P_ERR]

//>> GET_[ERROR_REG_RX_PCB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_RX_PCB_DATA_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_RX_PCB_DATA_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_RX_PCB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_RX_PCB_DATA_P_ERR]

//>> GET_[ERROR_REG_RX_PCB_DATA_P_ERR]
static inline bool GET_ERROR_REG_RX_PCB_DATA_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_RX_PCB_DATA_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_RX_PCB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_RX_PCB_DATA_P_ERR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> CLEAR_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline bool GET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_PIB_ADDR_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PIB_ADDR_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PIB_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_PIB_ADDR_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PIB_ADDR_P_ERR]

//>> SET_[ERROR_REG_PIB_ADDR_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PIB_ADDR_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PIB_ADDR_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_PIB_ADDR_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PIB_ADDR_P_ERR]

//>> SET_[ERROR_REG_PIB_ADDR_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PIB_ADDR_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PIB_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_PIB_ADDR_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PIB_ADDR_P_ERR]

//>> CLEAR_[ERROR_REG_PIB_ADDR_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PIB_ADDR_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PIB_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_PIB_ADDR_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PIB_ADDR_P_ERR]

//>> GET_[ERROR_REG_PIB_ADDR_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PIB_ADDR_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PIB_ADDR_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_PIB_ADDR_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PIB_ADDR_P_ERR]

//>> GET_[ERROR_REG_PIB_ADDR_P_ERR]
static inline bool GET_ERROR_REG_PIB_ADDR_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PIB_ADDR_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_PIB_ADDR_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PIB_ADDR_P_ERR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> CLEAR_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline bool GET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_PIB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PIB_DATA_P_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PIB_DATA_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_PIB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PIB_DATA_P_ERR]

//>> SET_[ERROR_REG_PIB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PIB_DATA_P_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PIB_DATA_P_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_PIB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PIB_DATA_P_ERR]

//>> SET_[ERROR_REG_PIB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PIB_DATA_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PIB_DATA_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_PIB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PIB_DATA_P_ERR]

//>> CLEAR_[ERROR_REG_PIB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PIB_DATA_P_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PIB_DATA_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_PIB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PIB_DATA_P_ERR]

//>> GET_[ERROR_REG_PIB_DATA_P_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PIB_DATA_P_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PIB_DATA_P_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_PIB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PIB_DATA_P_ERR]

//>> GET_[ERROR_REG_PIB_DATA_P_ERR]
static inline bool GET_ERROR_REG_PIB_DATA_P_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PIB_DATA_P_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_PIB_DATA_P_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PIB_DATA_P_ERR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> CLEAR_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PCB_FSM_ERROR]

//>> GET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PCB_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_FSM_ERROR]

//>> GET_[ERROR_REG_PCB_FSM_ERROR]
static inline bool GET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_DEC_MCAST_GRP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DEC_MCAST_GRP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DEC_MCAST_GRP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_DEC_MCAST_GRP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DEC_MCAST_GRP_ERR]

//>> SET_[ERROR_REG_DEC_MCAST_GRP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DEC_MCAST_GRP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DEC_MCAST_GRP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_DEC_MCAST_GRP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DEC_MCAST_GRP_ERR]

//>> SET_[ERROR_REG_DEC_MCAST_GRP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DEC_MCAST_GRP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_DEC_MCAST_GRP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_DEC_MCAST_GRP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DEC_MCAST_GRP_ERR]

//>> CLEAR_[ERROR_REG_DEC_MCAST_GRP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_DEC_MCAST_GRP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_DEC_MCAST_GRP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_DEC_MCAST_GRP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_DEC_MCAST_GRP_ERR]

//>> GET_[ERROR_REG_DEC_MCAST_GRP_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_DEC_MCAST_GRP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_DEC_MCAST_GRP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_DEC_MCAST_GRP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DEC_MCAST_GRP_ERR]

//>> GET_[ERROR_REG_DEC_MCAST_GRP_ERR]
static inline bool GET_ERROR_REG_DEC_MCAST_GRP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_DEC_MCAST_GRP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_DEC_MCAST_GRP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DEC_MCAST_GRP_ERR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> CLEAR_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CL_FSM_ERROR]

//>> GET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CL_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_FSM_ERROR]

//>> GET_[ERROR_REG_CL_FSM_ERROR]
static inline bool GET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> CLEAR_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline bool GET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> CLEAR_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline bool GET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> CLEAR_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_TYPE_ERROR]

//>> GET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_TYPE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TYPE_ERROR]

//>> GET_[ERROR_REG_INT_TYPE_ERROR]
static inline bool GET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> CLEAR_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CL_DATA_ERROR]

//>> GET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CL_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_DATA_ERROR]

//>> GET_[ERROR_REG_CL_DATA_ERROR]
static inline bool GET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> CLEAR_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INFO_ERROR]

//>> GET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INFO_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INFO_ERROR]

//>> GET_[ERROR_REG_INFO_ERROR]
static inline bool GET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> CLEAR_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_SEQ_ERROR]

//>> GET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_SEQ_ERROR]

//>> GET_[ERROR_REG_SEQ_ERROR]
static inline bool GET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> CLEAR_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline bool GET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> CLEAR_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline bool GET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> CLEAR_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[ERROR_REG_CHIPLET_OFFLINE]
static inline bool GET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> CLEAR_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline bool GET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PLL_UNLOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PLL_UNLOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> GET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PLL_UNLOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> CLEAR_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_FSM_ERROR]

//>> GET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_FSM_ERROR]

//>> GET_[ERROR_REG_QME_FSM_ERROR]
static inline bool GET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW]


//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7]

//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7]

//>> PREP_[OPCG_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_REG0]

//>> GET_[OPCG_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_REG0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG0;
#endif
    return fapi2::getScom(i_target, OPCG_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_REG0]

//>> PUT_[OPCG_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_REG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return fapi2::putScom(i_target, OPCG_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_REG0]


//>> SET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_MODE]

//>> SET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_MODE]

//>> SET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUNN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_MODE]

//>> CLEAR_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUNN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUNN_MODE]

//>> GET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUNN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_MODE]

//>> GET_[OPCG_REG0_RUNN_MODE]
static inline bool GET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUNN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_MODE]

//>> SET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_GO]

//>> SET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_GO]

//>> SET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_GO]

//>> CLEAR_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_GO]

//>> GET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_GO]

//>> GET_[OPCG_REG0_OPCG_GO]
static inline bool GET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_GO]

//>> SET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_SCAN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_SCAN0]

//>> SET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_SCAN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_SCAN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_SCAN0]

//>> SET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUN_SCAN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_SCAN0]

//>> CLEAR_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUN_SCAN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUN_SCAN0]

//>> GET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUN_SCAN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_SCAN0]

//>> GET_[OPCG_REG0_RUN_SCAN0]
static inline bool GET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUN_SCAN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_SCAN0]

//>> SET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_SCAN0_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_SCAN0_MODE]

//>> SET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_SCAN0_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_SCAN0_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_SCAN0_MODE]

//>> SET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_SCAN0_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_SCAN0_MODE]

//>> CLEAR_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_SCAN0_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_SCAN0_MODE]

//>> GET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_SCAN0_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_SCAN0_MODE]

//>> GET_[OPCG_REG0_SCAN0_MODE]
static inline bool GET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_SCAN0_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_SCAN0_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_SLAVE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_IN_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> CLEAR_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_IN_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_IN_SLAVE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline bool GET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_IN_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_MASTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_IN_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> CLEAR_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_IN_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_IN_MASTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline bool GET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_IN_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> SET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_KEEP_MS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_KEEP_MS_MODE]

//>> SET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_KEEP_MS_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_KEEP_MS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_KEEP_MS_MODE]

//>> SET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_KEEP_MS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_KEEP_MS_MODE]

//>> CLEAR_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_KEEP_MS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_KEEP_MS_MODE]

//>> GET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_KEEP_MS_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_KEEP_MS_MODE]

//>> GET_[OPCG_REG0_KEEP_MS_MODE]
static inline bool GET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_KEEP_MS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_KEEP_MS_MODE]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline bool GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline bool GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> CLEAR_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline bool GET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> CLEAR_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline bool GET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_STOP_RUNN_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_STOP_RUNN_ON_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_STOP_RUNN_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_STOP_RUNN_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> CLEAR_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_STOP_RUNN_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_STOP_RUNN_ON_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline bool GET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_STOP_RUNN_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> SET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_STARTS_BIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> SET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_STARTS_BIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_STARTS_BIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> SET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_STARTS_BIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> CLEAR_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_STARTS_BIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_STARTS_BIST]

//>> GET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_STARTS_BIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> GET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline bool GET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_STARTS_BIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> SET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_HLD_DLY_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> SET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_HLD_DLY_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_HLD_DLY_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> SET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUNN_HLD_DLY_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> CLEAR_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUNN_HLD_DLY_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> GET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUNN_HLD_DLY_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> GET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline bool GET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUNN_HLD_DLY_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> SET_[OPCG_REG0_LOOP_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_LOOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_LOOP_COUNT,
           OPCG_REG0_LOOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG0_LOOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_LOOP_COUNT]

//>> SET_[OPCG_REG0_LOOP_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_LOOP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_LOOP_COUNT,
           OPCG_REG0_LOOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG0_LOOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_LOOP_COUNT]

//>> GET_[OPCG_REG0_LOOP_COUNT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_LOOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_LOOP_COUNT,
           OPCG_REG0_LOOP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG0_LOOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_LOOP_COUNT]

//>> PREP_[OTPC_M_SECURITY_SWITCH_REGISTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_SECURITY_SWITCH_REGISTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_SECURITY_SWITCH_REGISTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OTPC_M_SECURITY_SWITCH_REGISTER]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_SECURITY_SWITCH_REGISTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_SECURITY_SWITCH_REGISTER;
#endif
    return fapi2::getScom(i_target, OTPC_M_SECURITY_SWITCH_REGISTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER]

//>> PUT_[OTPC_M_SECURITY_SWITCH_REGISTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_SECURITY_SWITCH_REGISTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return fapi2::putScom(i_target, OTPC_M_SECURITY_SWITCH_REGISTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OTPC_M_SECURITY_SWITCH_REGISTER]

//>> PREP_[OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1;
#endif
    return fapi2::getScom(i_target, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1]

//>> PUT_[OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return fapi2::putScom(i_target, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1]


//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.insertFromRight<OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]

//>> SET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.setBit<OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]

//>> CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return o_data.clearBit<OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.extractToRight<OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]

//>> GET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]
static inline bool GET_OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_SECURITY_SWITCH_REGISTER, OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1));
#endif
    return i_data.getBit<OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK]

//>> PREP_[OTPC_M_STATUS_REGISTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_STATUS_REGISTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_STATUS_REGISTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OTPC_M_STATUS_REGISTER]

//>> GET_[OTPC_M_STATUS_REGISTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_STATUS_REGISTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_STATUS_REGISTER;
#endif
    return fapi2::getScom(i_target, OTPC_M_STATUS_REGISTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER]

//>> PUT_[OTPC_M_STATUS_REGISTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_STATUS_REGISTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return fapi2::putScom(i_target, OTPC_M_STATUS_REGISTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OTPC_M_STATUS_REGISTER]


//>> SET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_ADDR_NVLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_ADDR_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_ADDR_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_ADDR_NVLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_ADDR_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_ADDR_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_ADDR_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_ADDR_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_ADDR_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_ADDR_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_ADDR_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_ADDR_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]

//>> GET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_ADDR_NVLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_ADDR_NVLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_ADDR_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]

//>> GET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]
static inline bool GET_OTPC_M_STATUS_REGISTER_ADDR_NVLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_ADDR_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_ADDR_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_ADDR_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_WRITE_NVLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_WRITE_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_WRITE_NVLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_WRITE_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_WRITE_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_WRITE_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_WRITE_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_WRITE_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]

//>> GET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_WRITE_NVLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_WRITE_NVLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]

//>> GET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]
static inline bool GET_OTPC_M_STATUS_REGISTER_WRITE_NVLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_WRITE_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_WRITE_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_WRITE_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_READ_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_READ_NVLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_READ_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_READ_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_READ_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_READ_NVLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_READ_NVLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_READ_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_READ_NVLD]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_READ_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_READ_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_READ_NVLD]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_READ_NVLD]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_READ_NVLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_READ_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_READ_NVLD]

//>> GET_[OTPC_M_STATUS_REGISTER_READ_NVLD]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_READ_NVLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_READ_NVLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_READ_NVLD]

//>> GET_[OTPC_M_STATUS_REGISTER_READ_NVLD]
static inline bool GET_OTPC_M_STATUS_REGISTER_READ_NVLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_READ_NVLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_READ_NVLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_READ_NVLD]

//>> SET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]
static inline bool GET_OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_CORR_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_CORR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_CORR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CORR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_CORR_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_CORR_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_CORR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_CORR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CORR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_CORR_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_CORR_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_CORR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_CORR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CORR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_CORR_ERR]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_CORR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_CORR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_CORR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CORR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_CORR_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_CORR_ERR]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_CORR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_CORR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CORR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_CORR_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_CORR_ERR]
static inline bool GET_OTPC_M_STATUS_REGISTER_CORR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_CORR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CORR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_CORR_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_UNCORR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_UNCORR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_UNCORR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]

//>> SET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_UNCORR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_UNCORR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_UNCORR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]

//>> SET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_UNCORR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_UNCORR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_UNCORR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_UNCORR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_UNCORR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_UNCORR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]

//>> GET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_UNCORR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_UNCORR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_UNCORR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]

//>> GET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]
static inline bool GET_OTPC_M_STATUS_REGISTER_UNCORR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_UNCORR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_UNCORR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_UNCORR_ERROR]

//>> SET_[OTPC_M_STATUS_REGISTER_DATA_REG_0_31]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DATA_REG_0_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_DATA_REG_0_31,
           OTPC_M_STATUS_REGISTER_DATA_REG_0_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DATA_REG_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DATA_REG_0_31]

//>> SET_[OTPC_M_STATUS_REGISTER_DATA_REG_0_31]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DATA_REG_0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_DATA_REG_0_31,
           OTPC_M_STATUS_REGISTER_DATA_REG_0_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DATA_REG_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DATA_REG_0_31]

//>> GET_[OTPC_M_STATUS_REGISTER_DATA_REG_0_31]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_DATA_REG_0_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_DATA_REG_0_31,
           OTPC_M_STATUS_REGISTER_DATA_REG_0_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DATA_REG_0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_DATA_REG_0_31]

//>> SET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_CTRL_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_CTRL_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CTRL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_CTRL_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_CTRL_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CTRL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_CTRL_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_CTRL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CTRL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_CTRL_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_CTRL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CTRL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]

//>> GET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_CTRL_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_CTRL_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CTRL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]

//>> GET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]
static inline bool GET_OTPC_M_STATUS_REGISTER_CTRL_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_CTRL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_CTRL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_CTRL_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DCOMP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_DCOMP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DCOMP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_DCOMP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DCOMP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_DCOMP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_DCOMP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_DCOMP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_DCOMP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_DCOMP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]
static inline bool GET_OTPC_M_STATUS_REGISTER_DCOMP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_DCOMP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_DCOMP_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]

//>> GET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]
static inline bool GET_OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR]

//>> SET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]

//>> SET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]

//>> SET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]

//>> GET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]

//>> GET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]
static inline bool GET_OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE]

//>> SET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]

//>> GET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]

//>> GET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]
static inline bool GET_OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.setBit<OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]

//>> CLEAR_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.clearBit<OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]

//>> GET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]

//>> GET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]
static inline bool GET_OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.getBit<OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY]

//>> SET_[OTPC_M_STATUS_REGISTER_RD_DATA_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_RD_DATA_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_RD_DATA_COUNT,
           OTPC_M_STATUS_REGISTER_RD_DATA_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RD_DATA_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_RD_DATA_COUNT]

//>> SET_[OTPC_M_STATUS_REGISTER_RD_DATA_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_STATUS_REGISTER_RD_DATA_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return o_data.insertFromRight<OTPC_M_STATUS_REGISTER_RD_DATA_COUNT,
           OTPC_M_STATUS_REGISTER_RD_DATA_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RD_DATA_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_STATUS_REGISTER_RD_DATA_COUNT]

//>> GET_[OTPC_M_STATUS_REGISTER_RD_DATA_COUNT]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_STATUS_REGISTER_RD_DATA_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_STATUS_REGISTER));
#endif
    return i_data.extractToRight<OTPC_M_STATUS_REGISTER_RD_DATA_COUNT,
           OTPC_M_STATUS_REGISTER_RD_DATA_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_STATUS_REGISTER_RD_DATA_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_STATUS_REGISTER_RD_DATA_COUNT]

//>> PREP_[REC_ERR_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_REG0]

//>> GET_[REC_ERR_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_REG0;
#endif
    return fapi2::getScom(i_target, REC_ERR_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_REG0]

//>> PUT_[REC_ERR_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_REG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return fapi2::putScom(i_target, REC_ERR_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_REG0]


//>> SET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_MASTER_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_MASTER_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_MASTER_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_MASTER_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_MASTER_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_MASTER_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_MASTER_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_MASTER_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_MASTER_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_MASTER_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_MASTER_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_MASTER_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_MASTER_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_MASTER_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_MASTER_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_MASTER_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_MASTER_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_MASTER_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_MASTER_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_MASTER_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_MASTER_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_MASTER_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_MASTER_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_MASTER_ERROR_CODE,
           REC_ERR_REG0_MASTER_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_MASTER_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_MASTER_ERROR_CODE]

//>> SET_[REC_ERR_REG0_MASTER_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_MASTER_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_MASTER_ERROR_CODE,
           REC_ERR_REG0_MASTER_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_MASTER_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_MASTER_ERROR_CODE]

//>> GET_[REC_ERR_REG0_MASTER_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_MASTER_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_MASTER_ERROR_CODE,
           REC_ERR_REG0_MASTER_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_MASTER_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_MASTER_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE1_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE1_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE1_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE1_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE1_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE1_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE1_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE1_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE1_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE1_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE1_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE1_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE1_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE1_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE1_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE1_ERROR_CODE,
           REC_ERR_REG0_SLAVE1_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE1_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE1_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE1_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE1_ERROR_CODE,
           REC_ERR_REG0_SLAVE1_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE1_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE1_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE1_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE1_ERROR_CODE,
           REC_ERR_REG0_SLAVE1_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE1_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE1_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE2_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE2_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE2_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE2_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE2_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE2_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE2_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE2_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE2_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE2_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE2_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE2_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE2_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE2_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE2_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE2_ERROR_CODE,
           REC_ERR_REG0_SLAVE2_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE2_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE2_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE2_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE2_ERROR_CODE,
           REC_ERR_REG0_SLAVE2_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE2_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE2_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE2_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE2_ERROR_CODE,
           REC_ERR_REG0_SLAVE2_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE2_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE2_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE3_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE3_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE3_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE3_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE3_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE3_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE3_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE3_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE3_ERROR_CODE,
           REC_ERR_REG0_SLAVE3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE3_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE3_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE3_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE3_ERROR_CODE,
           REC_ERR_REG0_SLAVE3_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE3_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE3_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE3_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE3_ERROR_CODE,
           REC_ERR_REG0_SLAVE3_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE3_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE3_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE4_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE4_ERROR_CODE,
           REC_ERR_REG0_SLAVE4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE4_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE4_ERROR_CODE,
           REC_ERR_REG0_SLAVE4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE4_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE4_ERROR_CODE,
           REC_ERR_REG0_SLAVE4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE4_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE4_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE5_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE5_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE5_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE5_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE5_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE5_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE5_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE5_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE5_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE5_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE5_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE5_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE5_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE5_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE5_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE5_ERROR_CODE,
           REC_ERR_REG0_SLAVE5_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE5_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE5_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE5_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE5_ERROR_CODE,
           REC_ERR_REG0_SLAVE5_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE5_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE5_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE5_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE5_ERROR_CODE,
           REC_ERR_REG0_SLAVE5_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE5_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE5_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE6_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE6_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE6_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE6_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE6_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE6_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE6_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE6_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE6_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE6_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE6_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE6_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE6_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE6_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE6_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE6_ERROR_CODE,
           REC_ERR_REG0_SLAVE6_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE6_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE6_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE6_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE6_ERROR_CODE,
           REC_ERR_REG0_SLAVE6_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE6_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE6_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE6_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE6_ERROR_CODE,
           REC_ERR_REG0_SLAVE6_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE6_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE6_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE7_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE7_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE7_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE7_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE7_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE7_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE7_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE7_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE7_ERROR_CODE,
           REC_ERR_REG0_SLAVE7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE7_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE7_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE7_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE7_ERROR_CODE,
           REC_ERR_REG0_SLAVE7_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE7_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE7_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE7_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE7_ERROR_CODE,
           REC_ERR_REG0_SLAVE7_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE7_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE7_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE8_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE8_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE8_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE8_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE8_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE8_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE8_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE8_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE8_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE8_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE8_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE8_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE8_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE8_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE8_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE8_ERROR_CODE,
           REC_ERR_REG0_SLAVE8_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE8_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE8_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE8_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE8_ERROR_CODE,
           REC_ERR_REG0_SLAVE8_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE8_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE8_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE8_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE8_ERROR_CODE,
           REC_ERR_REG0_SLAVE8_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE8_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE8_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE9_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE9_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE9_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE9_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE9_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE9_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE9_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE9_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE9_ERROR_CODE,
           REC_ERR_REG0_SLAVE9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE9_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE9_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE9_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE9_ERROR_CODE,
           REC_ERR_REG0_SLAVE9_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE9_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE9_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE9_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE9_ERROR_CODE,
           REC_ERR_REG0_SLAVE9_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE9_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE9_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE10_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE10_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE10_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE10_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE10_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE10_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE10_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE10_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE10_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE10_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE10_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE10_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE10_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE10_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE10_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE10_ERROR_CODE,
           REC_ERR_REG0_SLAVE10_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE10_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE10_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE10_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE10_ERROR_CODE,
           REC_ERR_REG0_SLAVE10_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE10_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE10_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE10_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE10_ERROR_CODE,
           REC_ERR_REG0_SLAVE10_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE10_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE10_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE11_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE11_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE11_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE11_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE11_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE11_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE11_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE11_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE11_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE11_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE11_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE11_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE11_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE11_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE11_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE11_ERROR_CODE,
           REC_ERR_REG0_SLAVE11_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE11_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE11_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE11_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE11_ERROR_CODE,
           REC_ERR_REG0_SLAVE11_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE11_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE11_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE11_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE11_ERROR_CODE,
           REC_ERR_REG0_SLAVE11_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE11_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE11_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE12_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE12_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE12_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE12_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE12_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE12_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE12_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE12_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE12_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE12_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE12_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE12_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE12_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE12_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE12_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE12_ERROR_CODE,
           REC_ERR_REG0_SLAVE12_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE12_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE12_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE12_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE12_ERROR_CODE,
           REC_ERR_REG0_SLAVE12_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE12_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE12_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE12_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE12_ERROR_CODE,
           REC_ERR_REG0_SLAVE12_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE12_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE12_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE13_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE13_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE13_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE13_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE13_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE13_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE13_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE13_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE13_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE13_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE13_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE13_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE13_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE13_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE13_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE13_ERROR_CODE,
           REC_ERR_REG0_SLAVE13_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE13_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE13_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE13_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE13_ERROR_CODE,
           REC_ERR_REG0_SLAVE13_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE13_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE13_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE13_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE13_ERROR_CODE,
           REC_ERR_REG0_SLAVE13_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE13_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE13_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE14_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE14_ERROR_CODE,
           REC_ERR_REG0_SLAVE14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE14_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE14_ERROR_CODE,
           REC_ERR_REG0_SLAVE14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE14_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE14_ERROR_CODE,
           REC_ERR_REG0_SLAVE14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE14_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE14_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE15_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE15_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE15_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE15_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE15_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.setBit<REC_ERR_REG0_SLAVE15_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG0_SLAVE15_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.clearBit<REC_ERR_REG0_SLAVE15_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE15_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE15_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]

//>> GET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG0_SLAVE15_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.getBit<REC_ERR_REG0_SLAVE15_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE15_RESPONSE_BIT]

//>> SET_[REC_ERR_REG0_SLAVE15_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE15_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE15_ERROR_CODE,
           REC_ERR_REG0_SLAVE15_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE15_ERROR_CODE]

//>> SET_[REC_ERR_REG0_SLAVE15_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG0_SLAVE15_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_REG0_SLAVE15_ERROR_CODE,
           REC_ERR_REG0_SLAVE15_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG0_SLAVE15_ERROR_CODE]

//>> GET_[REC_ERR_REG0_SLAVE15_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG0_SLAVE15_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG0));
#endif
    return i_data.extractToRight<REC_ERR_REG0_SLAVE15_ERROR_CODE,
           REC_ERR_REG0_SLAVE15_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG0_SLAVE15_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG0_SLAVE15_ERROR_CODE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
