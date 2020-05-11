/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00078.H $         */
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

#ifndef __PROC_REG00078_H_
#define __PROC_REG00078_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG]

//>> PUT_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG]


//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_START_CAL]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_DATA_SEL]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MEASURE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MAX_MODE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_MIN_MODE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_CAL_DONE]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_KVREF_TIMEOUT]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_TIMEOUT]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]

//>> SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]

//>> CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]

//>> GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]
static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG_VMEAS_RESULT_VALID]

//>> PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]

//>> CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]
static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_DNFIFO_RESET]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
